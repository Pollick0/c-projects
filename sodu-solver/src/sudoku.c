#include "sudoku.h"

int UNSOLVED = 81;
int progress = 0;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main ()
{
    int ** puzzle;
    Sudoku * sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    int x;
    
    while (UNSOLVED > 0)
    {
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);
        if (progress == 0)
        {
            break;
        }
    }
    printf("\n");
    
    printPuzzle(sudoku->squares);
    printf("Failed to solve puzzle!\n\n");
    
    return 0; 
}