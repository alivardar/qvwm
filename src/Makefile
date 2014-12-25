# Makefile.in generated automatically by automake 1.4 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


SHELL = /bin/sh

srcdir = .
top_srcdir = ..

prefix = /usr/local
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/qvwm
pkglibdir = $(libdir)/qvwm
pkgincludedir = $(includedir)/qvwm

top_builddir = ..

ACLOCAL = aclocal
AUTOCONF = autoconf
AUTOMAKE = automake
AUTOHEADER = autoheader

INSTALL = /usr/bin/ginstall -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
CC = gcc
CPP = gcc -E
CXX = g++
ESD_CFLAGS = 
ESD_CONFIG = /usr/bin/esd-config
ESD_LIBS = -L/usr/lib -lesd -laudiofile -lm
GDK_IMLIB_CFLAGS = @GDK_IMLIB_CFLAGS@
GDK_IMLIB_LIBS = @GDK_IMLIB_LIBS@
IMGDIR = /usr/local/share/qvwm/images
IMLIB_CFLAGS = -I/usr/X11R6/include
IMLIB_CONFIG = /usr/bin/imlib-config
IMLIB_LIBS = -L/usr/lib -lImlib -ljpeg -ltiff -lungif -lpng -lz -lm -lXext -L/usr/X11R6/lib -lSM -lICE -lXext -lX11
LEX = flex
LN_S = ln -s
MAINT = #
MAKEINFO = makeinfo
PACKAGE = qvwm
PATH_RM = /bin/rm
QVWMDIR = /usr/local/share/qvwm
SNDDIR = /usr/local/share/qvwm/sounds
VERSION = 1.1.12
YACC = bison -y

SUBDIRS = bitmaps

bin_PROGRAMS = qvwm

qvwm_SOURCES = main.cc main.h $(WINDOW_SRCS) $(BASE_SRCS) $(EVENT_SRCS) $(RC_SRCS) $(WM_SRCS) $(DESKTOP_SRCS) $(MENU_SRCS) $(TASKBAR_SRCS) $(PAGER_SRCS) $(IMAGE_SRCS) $(BUTTON_SRCS) $(DIALOG_SRCS) $(TOOLTIP_SRCS) $(AUDIO_SRCS) remote_cmd.cc remote_cmd.h


WINDOW_SRCS = qvwm.cc qvwm.h frame.cc titlebar.cc window.cc move.cc resize.cc resize_sp.cc rearrange.cc focus.cc focus_mgr.cc focus_mgr.h


BASE_SRCS = util.cc util.h message.h ver.h timer.cc timer.h function.cc function.h debug.cc debug.h hash.h list.h misc.h callback.h exec.cc exec.h 


EVENT_SRCS = event.cc event.h colormap.cc configure.cc property.cc key.cc key.h 


RC_SRCS = parse.cc parse.h yaccsrc.yy yaccsrc.h lexsrc.ll qvwmrc.cc qvwmrc.h 


WM_SRCS = mwm.cc mwm.h gnome.cc gnome.h session.cc session.h screen_saver.cc screen_saver.h 


DESKTOP_SRCS = desktop.cc desktop.h icon.cc icon.h switcher.cc switcher.h paging.cc paging.h info_display.cc info_display.h accessory.cc accessory.h


MENU_SRCS = menu.cc menu.h menu_func.cc startmenu.cc startmenu.h 

TASKBAR_SRCS = taskbar.cc taskbar.h tbutton.cc tbutton.h indicator.cc indicator.h 


PAGER_SRCS = pager.cc pager.h mini.cc mini.h 

IMAGE_SRCS = image.cc image.h pixmap_image.cc pixmap_image.h extra_image.cc extra_image.h 


BUTTON_SRCS = button.cc button.h string_button.cc string_button.h ctrl_button.cc fbutton.cc fbutton.h sbutton.cc sbutton.h


DIALOG_SRCS = dialog.cc dialog.h system_dialog.cc system_dialog.h radio_button.cc radio_button.h radio_set.cc radio_set.h resource.h exit_dialog.cc exit_dialog.h confirm_dialog.cc confirm_dialog.h 


TOOLTIP_SRCS = tooltip.cc tooltip.h 

AUDIO_SRCS = audio.cc audio.h audio_wav.cc audio_wav.h audio_au.cc audio_au.h audiodev.cc audiodev.h audiodev_alsa.cc audiodev_alsa.h audiodev_esd.cc audiodev_esd.h audiodev_oss.cc audiodev_oss.h audiodev_sun.cc audiodev_sun.h


# VPATH is not enough for lexsrc.ll and yaccsrc.yy
DEFS =  -DQVWMDIR=\"/usr/local/share/qvwm\" -DIMGDIR=\"/usr/local/share/qvwm/images\" -DSNDDIR=\"/usr/local/share/qvwm/sounds\" -DPATH_RM=\"/bin/rm\" -DHAVE_CONFIG_H -I$(top_builddir) -I$(srcdir)

qvwm_LDADD = -lfl

YFLAGS = -d

EXTRA_DIST = Imakefile Makefile.std
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
PROGRAMS =  $(bin_PROGRAMS)

CPPFLAGS = 
LDFLAGS = 
LIBS =  -lSM -lICE -lXss -L/usr/lib -lImlib -ljpeg -ltiff -lungif -lpng -lz -lm -lXext -L/usr/X11R6/lib -lSM -lICE -lXext -lX11 -lXext -lX11  -L/usr/X11R6/lib   -L/usr/lib -lesd -laudiofile -lm
X_CFLAGS =  -I/usr/X11R6/include
X_LIBS = -lXss -L/usr/lib -lImlib -ljpeg -ltiff -lungif -lpng -lz -lm -lXext -L/usr/X11R6/lib -lSM -lICE -lXext -lX11 -lXext -lX11  -L/usr/X11R6/lib
X_EXTRA_LIBS = 
X_PRE_LIBS =  -lSM -lICE
qvwm_OBJECTS =  main.o qvwm.o frame.o titlebar.o window.o move.o \
resize.o resize_sp.o rearrange.o focus.o focus_mgr.o util.o timer.o \
function.o debug.o exec.o event.o colormap.o configure.o property.o \
key.o parse.o yaccsrc.o lexsrc.o qvwmrc.o mwm.o gnome.o session.o \
screen_saver.o desktop.o icon.o switcher.o paging.o info_display.o \
accessory.o menu.o menu_func.o startmenu.o taskbar.o tbutton.o \
indicator.o pager.o mini.o image.o pixmap_image.o extra_image.o \
button.o string_button.o ctrl_button.o fbutton.o sbutton.o \
dialog.o system_dialog.o radio_button.o radio_set.o exit_dialog.o \
confirm_dialog.o tooltip.o audio.o audio_wav.o audio_au.o audiodev.o \
audiodev_alsa.o audiodev_esd.o audiodev_oss.o audiodev_sun.o \
remote_cmd.o
qvwm_DEPENDENCIES = 
qvwm_LDFLAGS = 
CXXFLAGS = -g -O2  -I/usr/X11R6/include  -I/usr/X11R6/include  -fpermissive
CXXCOMPILE = $(CXX) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
CXXLD = $(CXX)
CXXLINK = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@
LEX_OUTPUT_ROOT = lex.yy
LEXLIB = -lfl
CFLAGS = -g -O2  -I/usr/X11R6/include  -fpermissive
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  Makefile.am Makefile.in lexsrc.cc yaccsrc.cc


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = gtar
GZIP_ENV = --best
SOURCES = $(qvwm_SOURCES)
OBJECTS = $(qvwm_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .cc .ll .o .s .yy
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps src/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-binPROGRAMS:

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)

distclean-binPROGRAMS:

maintainer-clean-binPROGRAMS:

install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo "  $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`"; \
	     $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	  else :; fi; \
	done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	list='$(bin_PROGRAMS)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	done

.c.o:
	$(COMPILE) -c $<

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

qvwm: $(qvwm_OBJECTS) $(qvwm_DEPENDENCIES)
	@rm -f qvwm
	$(CXXLINK) $(qvwm_LDFLAGS) $(qvwm_OBJECTS) $(qvwm_LDADD) $(LIBS)
.cc.o:
	$(CXXCOMPILE) -c $<
.ll.cc:
	$(LEX) $(AM_LFLAGS) $(LFLAGS) $< && mv $(LEX_OUTPUT_ROOT).c $@
.yy.cc:
	$(YACC) $(AM_YFLAGS) $(YFLAGS) $< && mv y.tab.c $*.cc
	if test -f y.tab.h; then \
	if cmp -s y.tab.h $*.h; then rm -f y.tab.h; else mv y.tab.h $*.h; fi; \
	else :; fi
yaccsrc.hh: yaccsrc.cc


# This directory's subdirectories are mostly independent; you can cd
# into them and run `make' without going through this Makefile.
# To change the values of `make' variables: instead of editing Makefiles,
# (1) if the variable is set in `config.status', edit `config.status'
#     (which will cause the Makefiles to be regenerated when you run `make');
# (2) otherwise, pass the desired values on the `make' command line.



all-recursive install-data-recursive install-exec-recursive \
installdirs-recursive install-recursive uninstall-recursive  \
check-recursive installcheck-recursive info-recursive dvi-recursive:
	@set fnord $(MAKEFLAGS); amf=$$2; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    dot_seen=yes; \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done; \
	if test "$$dot_seen" = "no"; then \
	  $(MAKE) $(AM_MAKEFLAGS) "$$target-am" || exit 1; \
	fi; test -z "$$fail"

mostlyclean-recursive clean-recursive distclean-recursive \
maintainer-clean-recursive:
	@set fnord $(MAKEFLAGS); amf=$$2; \
	dot_seen=no; \
	rev=''; list='$(SUBDIRS)'; for subdir in $$list; do \
	  rev="$$subdir $$rev"; \
	  test "$$subdir" = "." && dot_seen=yes; \
	done; \
	test "$$dot_seen" = "no" && rev=". $$rev"; \
	target=`echo $@ | sed s/-recursive//`; \
	for subdir in $$rev; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"
tags-recursive:
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  test "$$subdir" = . || (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) tags); \
	done

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS: tags-recursive $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
   if test "$$subdir" = .; then :; else \
	    test -f $$subdir/TAGS && tags="$$tags -i $$here/$$subdir/TAGS"; \
   fi; \
	done; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags $(ETAGS_ARGS) $$tags  $$unique $(LISP) -o $$here/TAGS)

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = src

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
	for subdir in $(SUBDIRS); do \
	  if test "$$subdir" = .; then :; else \
	    test -d $(distdir)/$$subdir \
	    || mkdir $(distdir)/$$subdir \
	    || exit 1; \
	    chmod 777 $(distdir)/$$subdir; \
	    (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) top_distdir=../$(top_distdir) distdir=../$(distdir)/$$subdir distdir) \
	      || exit 1; \
	  fi; \
	done

info-am:
info: info-recursive
dvi-am:
dvi: dvi-recursive
check-am: all-am
check: check-recursive
installcheck-am:
installcheck: installcheck-recursive
install-exec-am: install-binPROGRAMS
install-exec: install-exec-recursive

install-data-am:
install-data: install-data-recursive

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-recursive
uninstall-am: uninstall-binPROGRAMS
uninstall: uninstall-recursive
all-am: Makefile $(PROGRAMS)
all-redirect: all-recursive
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs: installdirs-recursive
installdirs-am:
	$(mkinstalldirs)  $(DESTDIR)$(bindir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
	-test -z "lexsrcllyaccsrchhyaccsrccc" || rm -f lexsrcll yaccsrchh yaccsrccc
mostlyclean-am:  mostlyclean-binPROGRAMS mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-recursive

clean-am:  clean-binPROGRAMS clean-compile clean-tags clean-generic \
		mostlyclean-am

clean: clean-recursive

distclean-am:  distclean-binPROGRAMS distclean-compile distclean-tags \
		distclean-generic clean-am

distclean: distclean-recursive

maintainer-clean-am:  maintainer-clean-binPROGRAMS \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-recursive

.PHONY: mostlyclean-binPROGRAMS distclean-binPROGRAMS clean-binPROGRAMS \
maintainer-clean-binPROGRAMS uninstall-binPROGRAMS install-binPROGRAMS \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile install-data-recursive \
uninstall-data-recursive install-exec-recursive \
uninstall-exec-recursive installdirs-recursive uninstalldirs-recursive \
all-recursive check-recursive installcheck-recursive info-recursive \
dvi-recursive mostlyclean-recursive distclean-recursive clean-recursive \
maintainer-clean-recursive tags tags-recursive mostlyclean-tags \
distclean-tags clean-tags maintainer-clean-tags distdir info-am info \
dvi-am dvi check check-am installcheck-am installcheck install-exec-am \
install-exec install-data-am install-data install-am install \
uninstall-am uninstall all-redirect all-am all installdirs-am \
installdirs mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
