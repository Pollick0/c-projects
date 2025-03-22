#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;

typedef struct Box
{
    struct Box * next
} Box;

typedef struct Square
{
    int number;
    // 111101011
    // 987654321
    char code;
    Box * box;
    int row;
    int column;
} Square;

int ** createPuzzle();
void printPuzzle(int ** puzzle);
Square *** setUpPuzzle(int ** puzzle); 

#endif