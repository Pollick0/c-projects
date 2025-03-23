CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include
SRCDIR = ./src

SOURCES = $(wildcard $(SRCDIR)/*.c)

all: sudoku run clean

sudoku:
	$(CC) $(SOURCES) $(CFLAGS) -o sudoku

run:
	./sudoku

clean:
	rm -f sudoku
