#include "Algorithms.h"

#include <iostream>
using namespace std;

int EvilPuzzle[] = { 0,0,4, 5,0,1, 9,0,0,
                       0,2,0, 0,8,0, 0,3,0,
                       6,0,0, 0,0,0, 0,0,5,
                       0,0,8, 7,0,6, 3,0,0,
                       0,5,0, 0,0,0, 0,9,0,
                       0,0,3, 4,0,8, 5,0,0,
                       3,0,0, 0,0,0, 0,0,9,
                       0,8,0, 0,7,0, 0,6,0,
                       0,0,2, 8,0,5, 1,0,0 };

//Function Turns matrix into Puzzle object
void LoadGame(Puzzle* puzzle, int r, int c)
{
    Cell cell;
    cell.SetRow(r);
    cell.SetCol(c);
    cell.SetValue(EvilPuzzle[r * 9 + c]);
    if (cell.GetValue() != 0) {
        cell.SetHardwired(true);
        cell.SetSolution(cell.GetValue());
    }
    else {
        cell.SetSolution(0);
        cell.SetHardwired(false);
    }

    puzzle->SetCell(cell);
    return;
}

//Function Prints Solution of Cells
void printPuzzle(Puzzle puzzle, int rowSize, int colSize) {

    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {

            Cell curr = puzzle.GetCell(row, col);
            std::cout << curr.GetSolution() << " ";
        }
        std::cout << "" << std::endl;
    }
}


int main() {
    Puzzle puzzle;
    Algorithms alg;

    int rowSize = 9;
    int colSize = 9;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            LoadGame(&puzzle, i, j);
        }
    }

    printPuzzle(puzzle, rowSize, colSize);

    //sets Puzzle size
    puzzle.SetSize(rowSize);

    //Checks Empty; Should Return 53
    vector<Cell> empty = alg.FindAllEmpty(&puzzle);
    cout << "Return Total Number of Empty Values to Test" << endl;
    cout << empty.size() << endl;
    cout << "END CHECK EMPTY TEST" << endl;

    //-------------------------------------------------------------------

    //Checks Errors; Should Return 1 with first test
    Cell wrongVal = puzzle.GetCell(0,0);
    cout << "Solution Before: " << wrongVal.GetSolution() << endl;
    cout << "Value Before: " << wrongVal.GetValue() << endl;
    wrongVal.SetValue(1);
    cout << "Value After: " << wrongVal.GetValue() << endl;
    puzzle.SetCell(wrongVal);
    vector<Cell> error = alg.FindAllErrors(&puzzle);
    cout << "Return Total Number of Incorrect Values to Test" << endl;
    cout << error.size() << endl;
    cout << "END FIRST CHECK ERROR TEST" << endl;

    //-------------------------------------------------------------------

    //Checks Errors: Changes non-hardwired values to random
    //Checks Errors; Should Return 53 with this test
    Cell incorrectVal;
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (!puzzle.GetCell(row, col).isHardwired())
            {
                incorrectVal = puzzle.GetCell(row, col);
                incorrectVal.SetValue(1);
                puzzle.SetCell(incorrectVal);
            }
        }
    }

    vector<Cell> errors = alg.FindAllErrors(&puzzle);
    cout << "Return Total Number of Incorrect Values to Test" << endl;
    cout << errors.size() << endl;
    cout << "END SECOND CHECK ERROR TEST" << endl;
}