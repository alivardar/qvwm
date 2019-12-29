qvwm
----------------------
Qvwm is window manager for X11. This source uploaded from http://www.linuxprogramlama.com 

Main code  is from http://qvwm.sf.net

Changes

jim Huang  - 2004 Changes List 
Qvwm Codename Laserion
- qvwm-auto-restart.diff
  Provide a way to restart QVWM by touch /tmp/qvwm-restart.
  It's useful for programs to change the settings of QVWM.
- qvwm-fix-title.diff
  Solve the problem of missing title bar while running Java Swing
  application.
- qvwm-guess-defaultfont.diff
  Provide better guess on default font using.
- qvwm-fix-intersect.diff
  Fix the intersect algorithm.
---------------------------------------------------------------------
M.Ali VARDAR - 2003 Changes List
Qvwm Codename Laserion

- Added new configuration application qvwm-background (in utils package)
- Added new application qvwm-net (in utils package)
- Edited qvwm-run application (in utils package)
- Numlock or/and capslock if activated windows cant focused its fixed
- Removed ani files supported (its allready removed in qvwm2)
- All icons renew xpm file formatted and configuration files
- Added Save Desktop icons position  (only exit)
- Configuration files added in $HOME/.qvwm directory and redesigned

more information
See doc/*.
