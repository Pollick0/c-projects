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
        checkPuzzle(sudoku->squares, sudoku->boxes);
        printPuzzle(sudoku->squares);
        x++;
        printf("\n");
        printf("%d", x);
        printf("\n");
    }
    
    printf("\n");
    
    printPuzzle(sudoku->squares);
    
    return 0; 
}