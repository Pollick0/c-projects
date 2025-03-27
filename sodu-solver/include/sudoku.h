#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern char POSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box
{
    struct Box * next;
} Box;

typedef struct Square
{
    int number;
    // [0] [0] [0] [0] [0] [0] [0] [0] [0]
    // [9] [8] [7] [6] [5] [4] [3] [2] [1] index
    int possible[9];
    int solvable;
    Box * box;
    int row;
    int column;
} Square;

void solveSquare(Square * square);
int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Square *** setUpPuzzle(int ** puzzle); 

int checkPuzzle(Square *** square);
int updateSudoku(Square *** sudoku, int row, int column);

#endif