#include "../Dina/Algorithms.h"

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

int MediumPuzzle[] = { 0,7,9, 0,4,0, 5,0,0,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,0,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 0,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };

int EasyPuzzle[] = { 0,7,9, 8,4,0, 5,1,3,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,9,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 7,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };

//Function Turns matrix into Puzzle object
void LoadGameEvil(Puzzle* puzzle, int r, int c)
{
    Cell* cell = new Cell();
    cell->SetRow(r);
    cell->SetCol(c);
    cell->SetValue(EvilPuzzle[r * 9 + c]);
    if (cell->GetValue() != 0) {
        cell->SetHardwired(true);
        cell->SetSolution(cell->GetValue());
    }
    else {
        cell->SetSolution(0);
        cell->SetHardwired(false);
    }

    puzzle->SetCell(cell);
    return;
}

void LoadGameMed(Puzzle* puzzle, int r, int c)
{
    Cell* cell = new Cell();
    cell->SetRow(r);
    cell->SetCol(c);
    cell->SetValue(MediumPuzzle[r * 9 + c]);
    if (cell->GetValue() != 0) {
        cell->SetHardwired(true);
        cell->SetSolution(cell->GetValue());
    }
    else {
        cell->SetSolution(0);
        cell->SetHardwired(false);
    }

    puzzle->SetCell(cell);
    return;
}

void LoadGameEasy(Puzzle* puzzle, int r, int c)
{
    Cell* cell = new Cell();
    cell->SetRow(r);
    cell->SetCol(c);
    cell->SetValue(EasyPuzzle[r * 9 + c]);
    if (cell->GetValue() != 0) {
        cell->SetHardwired(true);
        cell->SetSolution(cell->GetValue());
    }
    else {
        cell->SetSolution(0);
        cell->SetHardwired(false);
    }

    puzzle->SetCell(cell);
    return;
}

int main() {
    Puzzle puzzle;
    Algorithms alg;

    int rowSize = 9;
    int colSize = 9;

    int input = 0;
    cout << "Enter 1 for Evil Puzzle, 2 for Medium Puzzle, or 3 for Easy Puzzle: ";
    cin >> input;
    switch (input) {
    case 1:
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                LoadGameEvil(&puzzle, i, j);
            }
        }
        cout << "----------------------------------------------------" << endl;
        cout << "----------------Using Evil Puzzle-------------------" << endl;
        cout << "----------------------------------------------------" << endl;
        break;
    case 2:
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                LoadGameMed(&puzzle, i, j);
            }
        }
        cout << "----------------------------------------------------" << endl;
        cout << "---------------Using Medium Puzzle------------------" << endl;
        cout << "----------------------------------------------------" << endl;
        break;
    case 3:
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                LoadGameEasy(&puzzle, i, j);
            }
        }
        cout << "----------------------------------------------------" << endl;
        cout << "----------------Using Easy Puzzle-------------------" << endl;
        cout << "----------------------------------------------------" << endl;
        break;
    }

    cout << "----------------------------------------------------" << endl;
    cout << "-----------------Printing Puzzle--------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    alg.PrintPuzzle(&puzzle);
    cout << "----------------------------------------------------" << endl;
    cout << "---------------End Printing Puzzle------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    //sets Puzzle size
    puzzle.SetSize(rowSize);

    //Checks Empty; Should Return 53
    cout << "----------------------------------------------------" << endl;
    cout << "------------Start Checking FindAllEmpty-------------" << endl;
    cout << "----------------------------------------------------" << endl;
    vector<Cell*> empty = alg.FindAllEmpty(&puzzle);
    cout << "------------Total Number of Empty Values------------" << endl;
    cout << "Size of Empty: " << empty.size() << endl;
    cout << "-----Print Row, Col, and Val of Each Empty Cell-----" << endl;
    for (int f = 0; f < empty.size(); f++)
    {
        cout << "Row: " << empty.at(f)->GetRow() << " Col: " << empty.at(f)->GetCol()
             << " Val: " << empty.at(f)->GetValue() << endl;
    }
    cout << "----------------------------------------------------" << endl;
    cout << "-------------End Checking FindAllEmpty--------------" << endl;
    cout << "----------------------------------------------------" << endl;

    //-------------------------------------------------------------------

    //Checks Errors; Should Return 1 with first test
    cout << "----------------------------------------------------" << endl;
    cout << "--------Start Checking FindAllErrors Test1----------" << endl;
    cout << "----------------------------------------------------" << endl;
    Cell* wrongVal = puzzle.GetCell(0,0);
    cout << "-------Print Solution and Value at Cell (0,0)-------" << endl;
    cout << "Solution Before: " << wrongVal->GetSolution() << endl;
    cout << "Value Before: " << wrongVal->GetValue() << endl;
    wrongVal->SetValue(1);
    cout << "------Set Value at Cell (0,0) to 1 (Incorrect)------" << endl;
    cout << "Value After: " << wrongVal->GetValue() << endl;
    puzzle.SetCell(wrongVal);
    vector<Cell*> error1 = alg.FindAllErrors(&puzzle);
    cout << "------------Total Number of Wrong Values------------" << endl; //Should be 1
    cout << error1.size() << endl;
    cout << "--------Print Row, Col, and Val of Wrong Cell-------" << endl; //Should be 1
    cout << "Row: " << wrongVal->GetRow() << " Col: " << wrongVal->GetCol()
         << " Val: " << wrongVal->GetValue() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "---------End Checking FindAllErrors Test1-----------" << endl;
    cout << "----------------------------------------------------" << endl;

    //-------------------------------------------------------------------

    //Checks Errors: Changes non-hardwired values to random
    //Checks Errors; Should Return 53 with this test
    cout << "----------------------------------------------------" << endl;
    cout << "--------Start Checking FindAllErrors Test2----------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "------Set Empty Cells' Value to 1 (Incorrect)-------" << endl;
    Cell* incorrectVal;
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (!puzzle.GetCell(row, col)->isHardwired())
            {
                incorrectVal = puzzle.GetCell(row, col);
                incorrectVal->SetValue(1);
                puzzle.SetCell(incorrectVal);
            }
        }
    }

    vector<Cell*> error2 = alg.FindAllErrors(&puzzle);
    cout << "------------Total Number of Wrong Values------------" << endl; //Should be 53, 45, 40 respectively
    cout << error2.size() << endl;
    cout << "--------Print Row, Col, and Val of Wrong Cell-------" << endl; //Should be 53, 45, 40 respectively
    for (int g = 0; g < error2.size(); g++)
    {
        cout << "Row: " << error2.at(g)->GetRow() << " Col: " << error2.at(g)->GetCol()
             << " Val: " << error2.at(g)->GetValue() << endl;
    }
    cout << "----------------------------------------------------" << endl;
    cout << "---------End Checking FindAllErrors Test2-----------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "-----------------Printing Puzzle--------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    alg.PrintPuzzle(&puzzle);
    cout << "----------------------------------------------------" << endl;
    cout << "---------------End Printing Puzzle------------------" << endl;
    cout << "----------------------------------------------------" << endl;

    //BEGIN ZALEN TEST
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "---------------TEST SOLVE BRUTE FORCE---------------" << endl;
    cout << "----------------------------------------------------" << endl;
    bool solved = alg.SolveBruteForce(&puzzle);
    cout << "The Puzzle is Solved (Brute Force): " << solved << endl; //will return 1 until LoadGame is fixed
    cout << "----------------------------------------------------" << endl;
    cout << "-------------END TEST SOLVE BRUTE FORCE-------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "-----------------TEST CHECK PUZZLE------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    bool checked = alg.CheckPuzzle(&puzzle);
    cout << "The Puzzle is Checked: " << checked << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------END TEST CHECK PUZZLE---------------" << endl;
    cout << "----------------------------------------------------" << endl;
    //END ZALEN TEST

    //BEGIN DINA TEST
    cout << "----------------------------------------------------" << endl;
    cout << "---------------TEST RANK DIFFICULTY-----------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Print Rank Difficulty: " << endl;
    alg.RankDifficulty(&puzzle);
    cout << "----------------------------------------------------" << endl;
    cout << "-------------END TEST RANK DIFFICULTY---------------" << endl;
    cout << "----------------------------------------------------" << endl;
    //END DINA TEST

    return 0;
}
