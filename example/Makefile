##
## Makefile for libmenu
## by lenormf
##

EXAMPLES = \
	   simple

LIBMENU = $(PWD)/../src/libmenu.a

all: $(LIBMENU)
	$(foreach d,$(EXAMPLES),cd $(d) && make all)

$(LIBMENU):
	cd ../src && make static

clean:
	$(foreach d,$(EXAMPLES),cd $(d) && make clean)

distclean:
	$(foreach d,$(EXAMPLES),cd $(d) && make distclean)

re:
	$(foreach d,$(EXAMPLES),cd $(d) && make re)
