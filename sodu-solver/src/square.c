#include "sudoku.h"

int solveSquare(Square * square)
{
    int x;

    for (x = 0; x < 9; x++) 
    {

        if (square->possible[x] == 0) 
        {    
            square->number = x + 1;
            square->solvable = 0;
            UNSOLVED--;
            break;  // **Add a break to stop after finding the first valid number**
        }
    }
    return 1;
}