// Includes code from Prof.Lord's LoadPrintPuzzle.cpp
//                    Dylon's puzzleCellTest.cpp
//                    Anthony's testing code

#include <iostream>
#include "./../Dylon/Puzzle.h"
#include "./../Alexis/History.h"
#include "./../Anthony/Cell.h"
#include "GameEngine.h"
using namespace std;

int EvilPuzzle[] = {   0,0,4, 5,0,1, 9,0,0,
                       0,2,0, 0,8,0, 0,3,0,
                       6,0,0, 0,0,0, 0,0,5,
                       0,0,8, 7,0,6, 3,0,0,
                       0,5,0, 0,0,0, 0,9,0,
                       0,0,3, 4,0,8, 5,0,0,
                       3,0,0, 0,0,0, 0,0,9,
                       0,8,0, 0,7,0, 0,6,0,
                       0,0,2, 8,0,5, 1,0,0   };

int EvilPuzzleSolution[] = {   8,3,4, 5,6,1, 9,2,7,
                               7,2,5, 9,8,4, 6,3,1,
                               6,1,9, 2,3,7, 4,8,5,
                               1,9,8, 7,5,6, 3,4,2,
                               4,5,6, 1,2,3, 7,9,8,
                               2,7,3, 4,9,8, 5,1,6,
                               3,4,7, 6,1,2, 8,5,9,
                               5,8,1, 3,7,9, 2,6,4,
                               9,6,2, 8,4,5, 1,7,3   };


// Added SetSolution to Prof's LoadGame when the cell is not hardwired
void LoadGame(Puzzle * puzzle, int r, int c)
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
        // cell.SetSolution(0);
        cell.SetHardwired(false);
        cell.SetSolution(EvilPuzzleSolution[r * 9 + c]);
    }
    for (int i = 0; i < 9; i++) {
        cell.GetNotes()[i] = 0;
    }
    puzzle->SetCell(cell);
    return;
}


void PrintGame(Puzzle * puzzle, int r, int c)
{
    int v = puzzle->GetCell(r, c)->GetValue();
    if ((c == 0) || (c == 3) || (c == 6)) {
        cout << "||";
        if (v != 0) cout << ' ' << v << ' ';
        else cout << "   ";
    }
    else {
        cout << "|";
        if (v != 0) cout << ' ' << v << ' ';
        else cout << "   ";
    }
    if (c == 8) {
        cout << "||\n";
        if ((r == 2) || (r == 5)) cout << "||===|===|===||===|===|===||===|===|===||\n";
        else if (r != 8) cout << "||---|---|---||---|---|---||---|---|---||\n";
    }
    return;
}

// Added PrintNotes to Dylon's testing function
void printCellData(Puzzle puzzle, int randomRow, int randomCol){

    cout << "" << std::endl;
    cout << "" << std::endl;
    cout << "*** Printing Cell Data for Cell at Row " << randomRow+1 << " Column " << randomCol+1 << " ***" << std::endl;
    Cell* curr = puzzle.GetCell(randomRow,randomCol);

    cout << "Solution: " << curr->GetSolution() << std::endl;
    cout << "Value: " << curr->GetValue() << std::endl;
    cout << "Is it hard wired? " << curr->isHardwired() << std::endl;
    cout<<"Notes: ";
    curr->PrintNotes();
    cout << "*****************************************************" << std::endl;

}

// Test 
int main() {
    Puzzle puzzle;
    History history;
    GameEngine g;

    int rowSize = 9;
    int colSize = 9;

    cout<<"----------Test---------"<<endl;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            LoadGame(&puzzle, i, j);
        }
    }

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&puzzle, i, j);
        }
    }


    g.SetUp(&puzzle, &history);

    // Test setting a value in puzzle cell

    // Set an illegal value to a legal location
    g.SetCurrentValue(40);
    g.SetValue(4, 50);

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&puzzle, i, j);
        }
    }

    // Set a legal value to an illegal location
    g.SetCurrentValue(3);
    g.SetValue(3, 15);

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&puzzle, i, j);
        }
    }

    // Set a legal value to a legal location
    g.SetCurrentValue(3);
    g.SetValue(0, 0);

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&puzzle, i, j);
        }
    }

    // Set a legal value to a hard-wired location
    g.SetCurrentValue(5);
    g.SetValue(0, 2);

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&puzzle, i, j);
        }
    }
    
    // Test for setting a note in a puzzle cell

    // Set an illegal note to a legal location

    // Set a legal note to a legal location

    // Set a legal note to a hard-wired location

    // Add a note to a cell with existing note



    // Test for undoing moves

    // Undo with entry == NULL
    // Output - no change and empty history stack
    // g.Undo();
    // cout<<"The game did not crash with no change."<<endl;


    // Undo with one existing entry - value
    // Output - most recent entry in history removed and empty history stack
    // int orig = puzzle.GetCell(0, 0)->GetValue();
    // cout<<"orig "<<orig<<endl;

    // g.SetCurrentValue(5);
    // g.SetValue(0, 0);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(puzzle, i, j);
    //     }
    // }

    // int ans = puzzle.GetCell(0, 0)->GetValue();
    // cout<<"ans "<<ans<<endl;

    // g.Undo();

    // int newv = puzzle.GetCell(0, 0)->GetValue();
    // cout<<"newv "<<ans<<endl;

    // if (ans == 0) {
    //     cout<<"0, 0: "<<ans<<"     Test: Pass"<<endl;
    // } else {
    //     cout<<ans<<"     Test: Fail"<<endl;
    // }

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&puzzle, i, j);
    //     }
    // }


    // Undo with multiple existing entry - value
    // Output - most recent entry in history removed and ramianing history stack
    // g.SetCurrentValue(5);
    // g.SetValue(0, 0);
    // g.SetCurrentValue(9);
    // g.SetValue(0, 0);
    // cout<<"0, 0: 5  9"<<endl;
    // g.Undo();
    // ans = p.GetCell(0, 0).GetValue();
    // if (ans == 5) {
    //     cout<<"0, 0: "<<ans<<"     Test: Pass"<<endl;
    // } else {
    //     cout<<ans<<"     Test: Fail"<<endl;
    // }

    // One entry on stack
    // g.Undo();

    // Undo with multiple existing entry - notes
    // Output - most recent entry in history removed and ramianing history stack
    // g.SetCurrentValue(9);
    // g.SetNote(2, 2);
    // review how to SetNote with note value


    // Test UndoUntilCorret()
    // UndoUntilCorret with entry == NULL
    // Output - no change and empty history stack
    // g.UndoUntilCorrect();
    // cout<<"The game did not crash with no change."<<endl;


    // UndoUntilCorret with one False entry 
    // Output - one entry removed and empty history stack
    // g.SetCurrentValue(4);
    // g.SetValue(2, 2);
    // g.UndoUntilCorrect();
    // ans = p.GetCell(2, 2).GetValue();
    // if (ans == 0) {
    //     cout<<"2, 2: "<<ans<<"     Test: Pass"<<endl;
    // } else {
    //     cout<<ans<<"     Test: Fail"<<endl;
    // }

    // UndoUntilCorret with one True entry 
    // Output - no change in histroy stack
    // int sol = p.GetCell(2, 2).GetSolution();
    // g.SetCurrentValue(sol);
    // g.SetValue(2, 2);
    // g.UndoUntilCorrect();
    // ans = p.GetCell(2, 2).GetValue();
    // if (ans == sol) {
    //     cout<<"2, 2: "<<ans<<"     Test: Pass"<<endl;
    // } else {
    //     cout<<ans<<"     Test: Fail"<<endl;
    // }

    // UndoUntilCorret with mutiple entries (FIRST - T, T, F, F - LAST)
    // Output - False entries removed in the histroy stack
    // stack already has one T
    // int sol1 = p.GetCell(2, 1).GetSolution();
    // g.SetCurrentValue(sol1);
    // g.SetValue(2, 1);
    // g.SetCurrentValue(4);
    // g.SetValue(2, 2);
    // g.SetCurrentValue(6);
    // g.SetValue(2, 2);
    // ans = p.GetCell(2, 2).GetValue();
    // if (ans == sol) {
    //     cout<<"2, 2: "<<ans<<"    Test: Pass"<<endl;
    // } else {
    //     cout<<ans<<"     Test: Fail"<<endl;
    // }

    // Two T 
    // g.Undo();
    // g.Undo();

    // UndoUntilCorret with mutiple entries (FIRST - F, F, F, F - LAST)
    // Output - False entries removed and empty history stack
    // g.SetCurrentValue(4);
    // g.SetValue(2, 2);
    // g.SetCurrentValue(6);
    // g.SetValue(2, 2);
    // g.SetCurrentValue(8);
    // g.SetValue(2, 2);
    // g.SetCurrentValue(3);
    // g.SetValue(2, 2);
    // ans = p.GetCell(2, 2).GetValue();
    // if (ans == 0) {
    //     cout<<"2, 2: "<<ans<<"    Test: Pass"<<endl;
    // } else {
    //     cout<<ans<<"     Test: Fail"<<endl;
    // }

    // UndoUntilCorret with mutiple entries (FIRST - T, T, F, T - LAST)
    // Output - no change in histroy stack
    // (Try with two notes, one False, and sol for same cell)

}