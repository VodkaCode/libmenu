##
## Makefile for libmenu
## by lenormf
##

NAME = menu

LIB_IMPLEMENTATION = sdl2.0

SRC = \
      error.c

IMPL_SRC = \
	   menu.c \
	   font.c \
	   vertical.c \
	   node.c \
	   button.c

OBJ = $(addprefix $(LIB_IMPLEMENTATION)/,$(IMPL_SRC:.c=.o)) $(SRC:.c=.o)

CC = gcc
CFLAGS = -I$(PWD) -Wall -Wextra $(shell sdl2-config --cflags)

all: static

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

static: $(OBJ)
	ar rcs lib$(NAME).a $(OBJ)

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f libmenu.a libmenu.so

re: distclean all
