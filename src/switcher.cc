/*
 * switcher.cc
 *
 * Copyright (C) 1995-2001 Kenichi Kourai
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with qvwm; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include "main.h"
#include "qvwm.h"
#include "switcher.h"
#include "qvwmrc.h"
#include "timer.h"
#include "key.h"
#include "focus_mgr.h"
#include "timer.h"

Timer* TaskSwitcher::swTimer;

TaskSwitcher::TaskSwitcher()
{
  XSetWindowAttributes attributes;
  unsigned long valueMask;
  
  /*
   * Create frame window.
   */
  attributes.background_pixel = SwitcherColor.pixel;
  attributes.override_redirect = True;
  attributes.event_mask = KeyPressMask | KeyReleaseMask | ExposureMask;
  valueMask = CWBackPixel | CWOverrideRedirect | CWEventMask;

  frame = XCreateWindow(display, root, 0, 0, 10, 10,
			0, CopyFromParent, InputOutput, CopyFromParent,
			valueMask, &attributes);

  /*
   * Create the window displaying title name.
   */
  valueMask = CWBackPixel;

  titleFrame = XCreateWindow(display, frame, 14, 0, 322, 24,
			     0, CopyFromParent, InputOutput, CopyFromParent,
			     valueMask, &attributes);

  title = XCreateWindow(display, titleFrame, 2, 2, 318, 20,
			0, CopyFromParent, InputOutput, CopyFromParent,
			valueMask, &attributes);

  if (SwitcherImage) {
    imgSwitcher = CreateImageFromFile(SwitcherImage, swTimer);
    if (imgSwitcher) {
      imgSwitcher->SetBackground(frame);
      imgTitle = NULL;
    }
    else {
      delete [] SwitcherImage;
      SwitcherImage = NULL;
    }
  }

  iterMap = new List<Qvwm>::Iterator(&focusMgr.GetMapList());
  iterUnmap = new List<Qvwm>::Iterator(&focusMgr.GetUnmapList());
}

TaskSwitcher::~TaskSwitcher()
{
  XDestroyWindow(display, frame);

  if (SwitcherImage) {
    QvImage::Destroy(imgSwitcher);
    QvImage::Destroy(imgTitle);
  }
}

void TaskSwitcher::MapSwitcher(int winNum)
{
  int col = (winNum + 6) / 7;

  ASSERT(rootQvwm);
  Rect rcRoot = rootQvwm->GetRect();

  rc = Rect((rcRoot.width - BASE_WIDTH) / 2,
	    (rcRoot.height - BASE_HEIGHT - col * 43) / 2,
	    BASE_WIDTH,
	    BASE_HEIGHT + col * 43);

  XMoveResizeWindow(display, frame, rc.x, rc.y, rc.width, rc.height);
  XMoveWindow(display, titleFrame, 14, 29 + col * 43);

  if (SwitcherImage) {
    QvImage::Destroy(imgTitle);
    imgTitle = imgSwitcher->GetOffsetImage(Point(14 + 2, 29 + col * 43 + 2));
    imgTitle->SetBackground(title);
  }

  XMapWindow(display, titleFrame);
  XMapWindow(display, title);
  XMapRaised(display, frame);
}

/*
 * SwitchTask --
 *   Display task switcher and switch focus window.
 *   This routine must be called by modifier + code.
 *   mod is with LockMask.
 */
void TaskSwitcher::SwitchTask(Bool forward, KeyCode code, unsigned int mod)
{
  int winNum = focusMgr.GetAllNum();
  Qvwm* qvWm;
  
  if (winNum == 0)
    return;
  else if (winNum == 1) {
    qvWm = focusMgr.Top();
    if (qvWm == NULL)
      qvWm = focusMgr.TopUnmapList();

    qvWm->SetFocus();
    if (qvWm->CheckMapped())
      qvWm->RaiseWindow(True);
    else
      qvWm->RestoreWindow();
    qvWm->AdjustPage();
    return;
  }

  direct = forward;

  MapSwitcher(winNum);
  XSetInputFocus(display, frame, RevertToParent, CurrentTime);

  EventLoop(winNum, code, mod);
}

void TaskSwitcher::EventLoop(int winNum, KeyCode code, unsigned int mod)
{
  Qvwm* qvWm = GetFirstFocus();
  int focusWin;
  XEvent ev;
  int fd = ConnectionNumber(display);
  fd_set fds;
  struct timeval tm;

  if (Qvwm::focusQvwm == rootQvwm)
    focusWin = 0;
  else
    focusWin = direct ? 1 : winNum - 1;

  XGrabServer(display);

  while (1) {
    FD_ZERO(&fds);
    FD_SET(fd, &fds);

    while (XPending(display) != 0) {
      XNextEvent(display, &ev);

      switch (ev.type) {
      case Expose:
	DrawTaskSwitcher();
	ASSERT(qvWm);
	DrawTitle(qvWm->name);
	DrawPixmaps(winNum);
	DrawRect(focusWin, winNum);
    
	while (XCheckWindowEvent(display, ev.xexpose.window, ExposureMask,
				 &ev))
	  ;
	break;
    
      case KeyPress:
	if (ev.xkey.keycode == code && ev.xkey.state == mod) {
	  qvWm = direct ? GetNextFocus() : GetPrevFocus();
	  ASSERT(qvWm);
	  DrawTitle(qvWm->name);
	  
	  if (direct) {
	    focusWin++;
	    if (focusWin == winNum)
	      focusWin = 0;
	  }
	  else {
	    focusWin--;
	    if (focusWin == -1)
	      focusWin = winNum - 1;
	  }
	  DrawRect(focusWin, winNum);
	}
	if (XKeycodeToKeysym(display, ev.xkey.keycode, 0) == XK_Escape) {
	  XUnmapWindow(display, frame);
	  XUngrabServer(display);
	  
	  if (ClickToFocus)
	    XSetInputFocus(display, qvWm->GetWin(), RevertToParent,
			   CurrentTime);
	  else
	    XSetInputFocus(display, root, RevertToParent, CurrentTime);
	  return;
	}
	break;

      case KeyRelease:
	if (mod & ShiftMask) {
	  if (XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Shift_L &&
	      XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Shift_R)
	    break;
	}
	else if (mod & ControlMask) {
	  if (XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Control_L &&
	      XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Control_R)
	    break;
	}
	else if (mod & ShortCutKey::getAltMask()) {
	  if (XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Alt_L &&
	      XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Alt_R)
	    break;
	}
	else if (mod & ShortCutKey::getMetaMask()) {
	  if (XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Meta_L &&
	      XKeycodeToKeysym(display, ev.xkey.keycode, 0) != XK_Meta_R)
	    break;
	}

	XUnmapWindow(display, frame);
	XUngrabServer(display);
      
	if (qvWm->CheckMapped()) {
	  qvWm->SetFocus();
	  /*
	   * If a new active window has already have a focus, XSetInputFocus
	   * doesn't call and the window with a mouse pointer gets an input
	   * focus.  To avoid this problem, qvwm calls XSetInputFocus below.
	   */
	  XSetInputFocus(display, qvWm->GetWin(), RevertToParent, CurrentTime);
	  qvWm->RaiseWindow(True);
	}
	else
	  qvWm->RestoreWindow();
	qvWm->AdjustPage();
	return;
      }

      swTimer->CheckTimeout(&tm);
    }

    if (!swTimer->CheckTimeout(&tm)) {
      tm.tv_sec = 1;
      tm.tv_usec = 0;
	
      XFlush(display);
    }

#if defined(__hpux) && !defined(_XPG4_EXTENDED)
    if (select(fd + 1, (int *)&fds, 0, 0, &tm) == 0) {    // timeout
#else
    if (select(fd + 1, &fds, 0, 0, &tm) == 0) {    // timeout
#endif
      swTimer->CheckTimeout(&tm);
    }
  }
}

/*
 * Called firstly once
 */
Qvwm* TaskSwitcher::GetFirstFocus()
{
  Qvwm* qvWm;

  qvWm = iterMap->GetHead();
  if (qvWm) {
    LookMapList = True;
    if (Qvwm::focusQvwm == qvWm)
      qvWm = direct ? GetNextFocus() : GetPrevFocus();
  }
  else {
    qvWm = iterUnmap->GetHead();
    ASSERT(qvWm);
    LookMapList = False;
  }

  return qvWm;
}

/*
 * Get next window in the focus stack, including unmapped windows
 */
Qvwm* TaskSwitcher::GetNextFocus()
{
  Qvwm* qvWm;

  if (LookMapList) {
    qvWm = iterMap->GetNext();
    if (qvWm == NULL) {
      qvWm = iterUnmap->GetHead();
      if (qvWm)
	LookMapList = False;
      else {
	qvWm = iterMap->GetHead();
	ASSERT(qvWm);
      }
    }
  }
  else {
    qvWm = iterUnmap->GetNext();
    if (qvWm == NULL) {
      qvWm = iterMap->GetHead();
      if (qvWm)
	LookMapList = True;
      else {
	qvWm = iterUnmap->GetHead();
	ASSERT(qvWm);
      }
    }
  }

  return qvWm;
}

/*
 * Get prev window in the focus stack, including unmapped windows
 */
Qvwm* TaskSwitcher::GetPrevFocus()
{
  Qvwm* qvWm;

  if (LookMapList) {
    qvWm = iterMap->GetPrev();
    if (qvWm == NULL) {
      qvWm = iterUnmap->GetTail();
      if (qvWm)
	LookMapList = False;
      else {
	qvWm = iterMap->GetTail();
	ASSERT(qvWm);
      }
    }
  }
  else {
    qvWm = iterUnmap->GetPrev();
    if (qvWm == NULL) {
      qvWm = iterMap->GetTail();
      if (qvWm)
	LookMapList = True;
      else {
	qvWm = iterUnmap->GetTail();
	ASSERT(qvWm);
      }
    }
  }

  return qvWm;
}

/*
 * DrawTaskSwitcher --
 *   Draw task switcher.
 */
void TaskSwitcher::DrawTaskSwitcher()
{
  XPoint xp[3];
  
  xp[0].x = rc.width - 2;
  xp[0].y = 0;
  xp[1].x = 0;
  xp[1].y = 0;
  xp[2].x = 0;
  xp[2].y = rc.height - 2;
  
  XSetForeground(display, gc, gray.pixel);
  XDrawLines(display, frame, gc, xp, 3, CoordModeOrigin);
  
  xp[0].x = rc.width - 1;
  xp[0].y = 0;
  xp[1].x = rc.width - 1;
  xp[1].y = rc.height - 1;
  xp[2].x = 0;
  xp[2].y = rc.height - 1;
  
  XSetForeground(display, gc, darkGrey.pixel);
  XDrawLines(display, frame, gc, xp, 3, CoordModeOrigin);
  
  xp[0].x = rc.width - 3;
  xp[0].y = 1;
  xp[1].x = 1;
  xp[1].y = 1;
  xp[2].x = 1;
  xp[2].y = rc.height - 3;
  
  XSetForeground(display, gc, white.pixel);
  XDrawLines(display, frame, gc, xp, 3, CoordModeOrigin);
  
  xp[0].x = rc.width - 2;
  xp[0].y = 1;
  xp[1].x = rc.width - 2;
  xp[1].y = rc.height - 2;
  xp[2].x = 1;
  xp[2].y = rc.height - 2;
  
  XSetForeground(display, gc, darkGray.pixel);
  XDrawLines(display, frame, gc, xp, 3, CoordModeOrigin);
  
  /*
   * The frame of title area.
   */
  xp[0].x = TITLE_WIDTH - 2;
  xp[0].y = 0;
  xp[1].x = 0;
  xp[1].y = 0;
  xp[2].x = 0;
  xp[2].y = TITLE_HEIGHT - 2;

  XSetForeground(display, gc, darkGray.pixel);
  XDrawLines(display, titleFrame, gc, xp, 3, CoordModeOrigin);
  
  xp[0].x = TITLE_WIDTH - 1;
  xp[0].y = 0;
  xp[1].x = TITLE_WIDTH - 1;
  xp[1].y = TITLE_HEIGHT - 1;
  xp[2].x = 0;
  xp[2].y = TITLE_HEIGHT - 1;
  
  XSetForeground(display, gc, white.pixel);
  XDrawLines(display, titleFrame, gc, xp, 3, CoordModeOrigin);
  
  xp[0].x = TITLE_WIDTH - 3;
  xp[0].y = 1;
  xp[1].x = 1;
  xp[1].y = 1;
  xp[2].x = 1;
  xp[2].y = TITLE_HEIGHT - 3;
  
  XSetForeground(display, gc, darkGrey.pixel);
  XDrawLines(display, titleFrame, gc, xp, 3, CoordModeOrigin);
  
  xp[0].x = TITLE_WIDTH - 2;
  xp[0].y = 1;
  xp[1].x = TITLE_WIDTH - 2;
  xp[1].y = TITLE_HEIGHT - 2;
  xp[2].x = 1;
  xp[2].y = TITLE_HEIGHT - 2;
  
  XSetForeground(display, gc, SwitcherColor.pixel);
  XDrawLines(display, titleFrame, gc, xp, 3, CoordModeOrigin);
}

/*
 * DrawTitle --
 *   Draw title name.
 */
void TaskSwitcher::DrawTitle(const char* name)
{
  XRectangle ink, log;
  Point pt;

  XSetBackground(display, gc, SwitcherColor.pixel);
  XClearWindow(display, title);

  XmbTextExtents(fsTitle, name, strlen(name), &ink, &log);
  pt.x = 2 - log.x;
  pt.y = (TITLE_HEIGHT - log.height) / 2 - log.y;

  XSetForeground(display, gc, SwitcherStringColor.pixel);
  XmbDrawString(display, title, fsTitle, gc, pt.x, pt.y, name, strlen(name));
}

/*
 * DrawRect --
 *   Draw the rectangle which indicates that the window is selected.
 */
void TaskSwitcher::DrawRect(int focusWin, int winNum)
{
  int base;
  Rect rect(0, 0, 42, 42);

  if (winNum < 7) {
    base = (BASE_WIDTH - winNum * 43 - 3) / 2 + 3;
    if (direct)
      rect.x = base + ((focusWin - 1 + winNum) % winNum) * 43 + 1;
    else
      rect.x = base + ((focusWin + 1) % winNum) * 43 + 1;
    rect.y = 19 + 1;
  }
  else {
    base = 26;
    if (direct) {
      if (focusWin == 0) {
	rect.x = base + ((winNum - 1) % 7) * 43 + 1;
	rect.y = 19 + ((winNum - 1) / 7) * 43 + 1;
      }
      else {
	rect.x = base + ((focusWin + 6) % 7) * 43 + 1;
	rect.y = 19 + ((focusWin - 1) / 7) * 43 + 1;
      }
    }
    else {
      if (focusWin == winNum - 1) {
	rect.x = base + 1;
	rect.y = 19 + 1;
      }
      else {
	rect.x = base + ((focusWin + 1) % 7) * 43 + 1;
	rect.y = 19 + ((focusWin + 1) / 7) * 43 + 1;
      }
    }
  }

  /*
   * Erase the previous rectangle.
   */
  XSetLineAttributes(display, gc, 2, LineSolid, CapButt, JoinMiter);

  if (SwitcherImage) {
    XClearArea(display, frame,
	       rect.x - 1, rect.y - 1, rect.width + 1, 2, False);
    XClearArea(display, frame,
	       rect.x - 1, rect.y - 1, 2, rect.height + 1, False);
    XClearArea(display, frame,
	       rect.x + rect.width - 1, rect.y - 1, 2, rect.height + 1, False);
    XClearArea(display, frame,
	       rect.x - 1, rect.y + rect.height - 1, rect.width + 1, 2, False);
  }
  else {
    XSetForeground(display, gc, SwitcherColor.pixel);
    XDrawRectangle(display, frame, gc,
		   rect.x, rect.y, rect.width, rect.height);
  }

  /*
   * Draw new rectangle.
   */
  rect.x = base + (focusWin % 7) * 43 + 1;
  rect.y = 19 + (focusWin / 7) * 43 + 1;

  XSetForeground(display, gc, SwitcherActiveColor.pixel);
  XDrawRectangle(display, frame, gc, rect.x, rect.y, rect.width, rect.height);

  /*
   * Restore line thickness.
   */
  XSetLineAttributes(display, gc, 1, LineSolid, CapButt, JoinMiter);
}

/*
 * DrawPixmaps --
 *   Draw pixmaps which indicate windows.
 */
void TaskSwitcher::DrawPixmaps(int winNum)
{
  int base = 26, num = 0;

  if (winNum < 7)
    base = (BASE_WIDTH - winNum * 43 - 3) / 2 + 3;

  // draw windows in the map list
  List<Qvwm>::Iterator i(&focusMgr.GetMapList());

  for (Qvwm* qvWm = i.GetHead(); qvWm; qvWm = i.GetNext()) {
    ASSERT(num < winNum);
    DrawPixmap(qvWm, num, base);
    num++;
  }

  // draw windows in the unmap list
  List<Qvwm>::Iterator j(&focusMgr.GetUnmapList());

  for (Qvwm* qvWm = j.GetHead(); qvWm; qvWm = j.GetNext()) {
    ASSERT(num < winNum);
    DrawPixmap(qvWm, num, base);
    num++;
  }
}

void TaskSwitcher::DrawPixmap(Qvwm* qvWm, int num, int base)
{
  Point pt;

  pt.x = base + (num % 7) * 43 + 5;
  pt.y = 19 + (num / 7) * 43 + 5;

  QvImage* img = qvWm->imgLarge;  // use only here (not need Duplicate)
  img->Display(frame, pt);
}

void TaskSwitcher::Initialize()
{
  swTimer = new Timer();
}
