# Dan Makefiles for comp-phys 2021
# This build file is based on st form suckless.org
.POSIX:

include config.mk

SRC = main.c dan_math.c
OBJ = $(SRC:.c=.o)

all: options EX_8

options:
	@echo EX build options:
	@echo "CFLAGS  = $(STCFLAGS)"
	@echo "LDFLAGS = $(STLDFLAGS)"
	@echo "CC      = $(CC)"

#config.h:
#	cp config.def.h config.h

.c.o:
	gcc $(STCFLAGS) -c $<

main.o: dan_math.h
dan_math.o: dan_math.h

$(OBJ): dan_math.h config.mk

EX_8: $(OBJ)
	gcc -o $@ $(OBJ) $(STLDFLAGS)

clean:
	rm -f st $(OBJ) st-$(VERSION).tar.gz

dist: clean
	mkdir -p st-$(VERSION)
	cp -R FAQ LEGACY TODO LICENSE Makefile README config.mk\
		config.def.h st.info st.1 arg.h st.h win.h $(SRC)\
		st-$(VERSION)
	tar -cf - st-$(VERSION) | gzip > st-$(VERSION).tar.gz
	rm -rf st-$(VERSION)

.PHONY: all options clean dist install uninstall
