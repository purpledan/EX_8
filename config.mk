# EX_8 version
VERSION = 0.2

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

#X11INC = /usr/X11R6/include
#X11LIB = /usr/X11R6/lib

PKG_CONFIG = pkg-config

# includes and libs
INCS = `$(PKG_CONFIG) --cflags gsl` \
       `$(PKG_CONFIG) --cflags openblas`\
       `$(PKG_CONFIG) --cflags plplot`
LIBS = `$(PKG_CONFIG) --libs gsl` \
       `$(PKG_CONFIG) --libs openblas`\
       `$(PKG_CONFIG) --libs plplot`

# flags
STCPPFLAGS = -DVERSION=\"$(VERSION)\" -D_XOPEN_SOURCE=600
STCFLAGS = $(INCS) $(STCPPFLAGS) $(CPPFLAGS) $(CFLAGS)
STLDFLAGS = $(LIBS) $(LDFLAGS)


# compiler and linker
# CC = c99
