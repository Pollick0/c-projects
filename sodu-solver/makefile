CC = gcc
CFLAGS = -I$(IDIR)
LDFLAGS = -lncurses

IDIR = ./include
SRCDIR = ./src

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: sudoku run clean

sudoku: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o sudoku

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

run: sudoku
	./sudoku

clean:
	rm -f sudoku $(OBJECTS)
