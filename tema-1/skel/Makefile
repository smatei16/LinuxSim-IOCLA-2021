CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -utils.h
LIBS = -lm
SRCS = utils.c tema1.c
OBJS = $(SRCS:.c=.o)
MAIN = tema

build:	$(MAIN)
		@echo Successfully build.

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)
clean:
	rm *.o tema

checker:
	python3 checker.py
