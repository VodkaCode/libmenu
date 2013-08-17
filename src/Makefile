##
## Makefile for libmenu
## by lenormf
##

NAME = menu

LIB_IMPLEMENTATION = sdl2.0

SRC = \
      menu.c

OBJ = $(addprefix $(LIB_IMPLEMENTATION)/,$(SRC:.c=.o))

CC = gcc
CFLAGS = -I$(PWD) -Wall -Wextra $(sdl-config --cflags)

all: static

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

static: $(OBJ)
	ar rcs lib$(NAME).a $(OBJ)

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f libmenu.a libmenu.so
