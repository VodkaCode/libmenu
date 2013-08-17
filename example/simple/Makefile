##
## Makefile for libmenu
## by lenormf
##

NAME = simple

SRC = \
      main.c \
      ../utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -I $(PWD)/../../src
LDFLAGS = $(sdl-config --libs) -L $(PWD)/../../src -lmenu

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(NAME)

re: distclean all
