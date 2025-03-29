#include <stdio.h>
#include <stdlib.h>
#include <sudoku.h>

Sudoku * createSudoku(Square *** squares, Box ** boxes)
{
    Sudoku * sudoku;
    sudoku = malloc(sizeof(Sudoku));
    
    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;
}

Sudoku * setUpPuzzle(int ** puzzle)
{
    Square *** sudoku;
    Box ** boxes;
    int i, j, x;
    int currentBox = 0;

    sudoku = (Square***)malloc(sizeof(Square**)*9);
    boxes = createBoxes();

    // loop through rows
    for (i = 0; i < SIZE_ROWS; i++)
    {
        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);

        // loop through columns
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            // maloc space for each square
            sudoku[i][j] = (Square*)malloc(sizeof(Square));

            // assign number to sudoku adt
            sudoku[i][j]->number = puzzle[i][j];

            // assign row and column numbers to each square
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solvable = 9;

            boxes[currentBox]->squares[ boxes[currentBox]->numbers ] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for (x = 0; x < SIZE_COLUMNS; x++) 
            {
                sudoku[i][j]->possible[x] = 0;
            }

            if (j == 2)
                currentBox++;
            if (j == 5)
                currentBox++;
        }
        currentBox -= 2;
        if (i == 2)
            currentBox = 3;
        if (i == 5)
            currentBox = 6;
    }

    // loop through rows
    for (i = 0; i < SIZE_ROWS; i++)
    {
        // loop through columns
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            // checks if cell isn't 0, which means it has a number in it
            if (sudoku[i][j]->number != 0)
            {
                // If square != 0 then it's solvable
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return createSudoku(sudoku, boxes);
}


int updateSudoku(Square *** sudoku, int row, int column)
{
    int x;
    // current number
    int number = sudoku[row][column]->number;

    // loop through row squares
    for (x = 0; x < SIZE_ROWS; x++)
    {
        // check if a number is possible
        if (sudoku[x][column]->possible[number - 1] == 0)
        {
            // reduce solvable to say that there is one less number possible
            sudoku[x][column]->solvable--;
        }
        // else possible = 1, that value isn't valid for that square
        sudoku[x][column]->possible[number - 1] = 1; 
    }

    // loop through column squares
    for (x = 0; x < SIZE_COLUMNS; x++)
    {
        if (sudoku[row][x]->possible[number - 1] == 0)
        {
            sudoku[row][x]->solvable--;
        }
        sudoku[row][x]->possible[number - 1] = 1; 
    }

    return 1;
}


int checkPuzzle(Square *** sudoku, Box ** boxes)
{
    int i, j, x;

    // loop through rows
    for (i = 0; i < SIZE_ROWS; i++)
    {
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->solvable == 1)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);

                return 1
            }
        }
    }
    
    boxSingles(sudoku, boxes);

    return 1;
}


int ** createPuzzle()
{
    int ** puzzle;
    int i, j;
    int array[9][9] = {0, 1, 9,    0, 0, 2,     0, 0, 0,
                       4, 7, 0,    6, 9, 0,     0, 0, 1,
                       0, 0, 0,    4, 0, 0,     0, 9, 0,
                    
                    
                       8, 9, 4,    5, 0, 7,     0, 0, 0,
                       0, 0, 0,    0, 0, 0,     0, 0, 0, 
                       0, 0, 0,    2, 0, 1,     9, 5, 8,
                    
                    
                       0, 5, 0,    0, 0, 6,     0, 0, 0,
                       6, 0, 0,    0, 2, 8,     0, 7, 9,
                       0, 0, 0,    1, 0, 0,     8, 6, 0,
                      };

    puzzle = (int**)malloc(sizeof(int*)*9);
    for (i = 0; i < SIZE_ROWS; i++)
    {
        puzzle[i] = (int*)malloc(sizeof(int)*9);
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }
    return puzzle;
}


void printPuzzle(Square *** puzzle)
{
    int i, j;

    printf("-------------------------------\n");
    for (i = 0; i < SIZE_ROWS; i++)
    {
        // print each row
        printf("|");
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            printf(" %d ", puzzle[i][j]->number);
            if ((j + 1) % 3 == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
            printf("-------------------------------\n");
        }
    }
}


