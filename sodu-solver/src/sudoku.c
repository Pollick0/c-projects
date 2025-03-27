#include "sudoku.h"

int UNSOLVED = 81;
char POSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main ()
{
    int ** puzzle;
    Square *** sudoku;

    puzzle = createPuzzle();

    printPuzzle(puzzle);

    sudoku = setUpPuzzle(puzzle);

    checkPuzzle(sudoku);

    return 0; 
}