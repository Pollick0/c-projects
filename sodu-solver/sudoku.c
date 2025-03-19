#include "sudoku.h"

int main ()
{
    int ** puzzle;

    puzzle = createPuzzle();

    printPuzzle(puzzle);

    sudoku = setUpPuzzle(puzzle);

    return 0;
}