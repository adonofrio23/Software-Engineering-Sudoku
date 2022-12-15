// Includes code from Prof.Lord's LoadPrintPuzzle.cpp
//                    Dylon's puzzleCellTest.cpp
//                    Anthony's testing code


#include <iostream>
#include "./../Dylon/Puzzle.h"
#include "./../Alexis/History.h"
#include "./../Anthony/Cell.h"
#include "../Amanda/GameEngine.h"
#include "../Dina/Algorithms.h"
#include <vector>
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




// From Prof Lord's LoadPrintPuzzle.cpp
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
        cell.SetHardwired(false);
        cell.SetSolution(0);
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
void printCellData(Puzzle* puzzle, int randomRow, int randomCol){

    cout << "" << std::endl;
    cout << "*** Printing Cell Data for Cell at Row " << randomRow+1 << " Column " << randomCol+1 << " ***" << std::endl;
    Cell* curr = puzzle->GetCell(randomRow,randomCol);

    cout << "Solution: " << curr->GetSolution() << endl;
    cout << "Value: " << curr->GetValue() << endl;
    cout << "Is it hard wired? " << curr->isHardwired() << endl;
    cout<<"Notes: ";
    for(int i = 0; i < 9; i++) {
        cout << curr->GetNotes()[i] << " ";
    }
    cout<<endl;
    cout << "-------------------------------------------------" <<endl;

}

// Test 
int main() {
    Puzzle p;
    History h;
    Algorithms alg;

    int rowSize = 9;
    int colSize = 9;

    p.SetSize(rowSize);
    cout<<"-------------------Game-----------------"<<endl;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            LoadGame(&p, i, j);
        }
    }

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }

    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    GameEngine g(&p, &h);

    cout<<"---------Algorithms test---------"<<endl;

    vector<Cell* > empty = alg.FindAllEmpty(&p);
    cout << "Size of Empty: " << empty.size() << endl;

    // Set solutions
    alg.SolveBruteForce(&p);

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }

    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    cout<<"sol "<<p.GetCell(0,0)->GetSolution()<<endl;
    cout<<"sol "<<p.GetCell(0,1)->GetSolution()<<endl;

    g.SetCurrentValue(9);
    g.SetValue(0, 1);
    g.SetCurrentValue(3);
    g.SetValue(2, 1);

    vector<Cell*> errors = alg.FindAllErrors(&p);
    cout << "Size of Errors: " << errors.size() << endl;

    int rank = alg.RankDifficulty(&p);
    cout<<rank<<endl;


    // Test setting a value in puzzle cell

    // cout<<"----------Test: setting a value in puzzle cell---------"<<endl;
    // // Set an illegal value to a illegal location
    // cout<<"*** illegal value in illegal location ***"<<endl;
    // cout<<"Output: ";
    // g.SetCurrentValue(40);
    // g.SetValue(4, 50);
    // cout<<endl;

    // // Set a legal value to an illegal location
    // cout<<"*** legal value in illegal location ***"<<endl;
    // cout<<"Output: ";
    // g.SetCurrentValue(3);
    // g.SetValue(3, 15);
    // cout<<endl;


    // // Set a legal value to a legal location
    // cout<<"*** legal value in legal location ***"<<endl;
    // cout<<"Output: puzzle"<<endl;
    // g.SetCurrentValue(3);
    // g.SetValue(0, 0);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<endl;

    // // Set a legal value to a hard-wired location
    // cout<<"*** legal value in legal location ***"<<endl;
    // cout<<"Output: ";
    // g.SetCurrentValue(5);
    // g.SetValue(0, 2);
    
    // cout<<endl;

    // // Test for setting a note in a puzzle cell
    // cout<<"----------Test: setting a note in puzzle cell---------"<<endl;

    // // Set an illegal note to a legal location
    // cout<<"*** illegal note to a legal location ***"<<endl;
    // printCellData(&p, 2, 2);

    // g.ToggleNotesMode();
    // g.SetCurrentValue(20);
    // g.SetNote(2, 2);

    // cout<<"Output: ";
    // printCellData(&p, 2, 2);
    // // The current val 5 gets set into the note from the last test's value

    // // Set a legal note to a legal location
    // cout<<"*** legal note to a legal location ***"<<endl;
    // printCellData(&p, 0, 1);
    // g.SetCurrentValue(2);
    // g.SetNote(0, 1);

    // cout<<"Output: ";
    // printCellData(&p, 0, 1);

    // // Set a legal note to a hard-wired location
    // cout<<"*** legal note to a hard-wired location ***"<<endl;
    // printCellData(&p, 0, 2);

    // g.SetCurrentValue(2);
    // g.SetNote(0, 2);

    // cout<<"Output: ";
    // printCellData(&p, 0, 2);

    // // Add a note to a cell with existing note
    // cout<<"*** add a note to a cell with existing note ***"<<endl;
    // printCellData(&p, 0, 2);

    // g.SetCurrentValue(3);
    // g.SetNote(0, 2);

    // g.SetCurrentValue(4);
    // g.SetNote(0, 2);

    // cout<<"Output: ";
    // printCellData(&p, 0, 2);

    // g.ToggleNotesMode();

    // Test for undoing moves
    // cout<<"----------Test: undoing moves---------"<<endl;

    // Undo with entry == NULL
    // Output - no change and empty history stack

    // cout<<"*** undo when no move has been made *** "<<endl;

    // g.Undo();

    // cout<<"The game did not crash with no change."<<endl;


    // Undo with one existing entry - value
    // Output - most recent entry in history removed and empty history stack
    // cout<<"*** undo with one move *** "<<endl;

    // g.SetCurrentValue(5);
    // g.SetValue(0, 0);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }

    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // g.Undo();

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }

    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;


    // Undo with multiple existing entry - value
    // Output - most recent entry in history removed and ramianing history stack
    // cout<<"*** undo with multiple moves on one cell *** "<<endl;
    // g.SetCurrentValue(5);
    // g.SetValue(0, 0);
    // g.SetCurrentValue(9);
    // g.SetValue(0, 0);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }

    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // g.Undo();

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }

    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;


    // One entry on stack
    // g.Undo();

    // Undo with multiple existing entry - notes
    // Output - most recent entry in history removed and ramianing history stack
    // cout<<"*** undo with multiple note moves on one cell *** "<<endl;
    // printCellData(&p, 0, 0);

    // g.ToggleNotesMode();
    // g.SetCurrentValue(2);
    // g.SetValue(0, 0);

    // g.SetCurrentValue(3);
    // g.SetValue(0, 0);

    // printCellData(&p, 0, 0);

    // g.Undo();

    // printCellData(&p, 0, 0);


    // Test UndoUntilCorret()
    // UndoUntilCorret with entry == NULL
    // Output - no change and empty history stack
    // cout<<"*** undo untill correct with no moves *** "<<endl;
    // g.UndoUntilCorrect();
    // cout<<"The game did not crash with no change."<<endl;
    // cout<<endl;

    // UndoUntilCorret with multiple False entries
    // Output - one entry removed and empty history stack
    // cout<<"*** undo untill correct with multiple wrong entries *** "<<endl;
    // g.SetCurrentValue(5);
    // g.SetValue(0, 0);
    // g.SetCurrentValue(4);
    // g.SetValue(2, 2);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // g.UndoUntilCorrect();

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // UndoUntilCorret with mutiple True entries
    // Output - no change in histroy stack
    // cout<<"*** undo untill correct with multiple correct entries *** "<<endl;
    // int sol = p.GetCell(0, 0)->GetSolution();
    // g.SetCurrentValue(sol);
    // g.SetValue(0, 0);

    // sol = p.GetCell(2, 2)->GetSolution();
    // g.SetCurrentValue(sol);
    // g.SetValue(2, 2);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // g.UndoUntilCorrect();

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // UndoUntilCorret with mutiple entries (FIRST - T, T, F, F - LAST)
    // Output - False entries removed in the histroy stack

    // cout<<"*** undo untill correct with two correct and wrong entries *** "<<endl;
    // stack already has two T entries
    // g.SetCurrentValue(9);
    // g.SetValue(0, 1);
    // g.SetCurrentValue(3);
    // g.SetValue(2, 1);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // g.UndoUntilCorrect();

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // Two T 
    // g.Undo();
    // g.Undo();

    // UndoUntilCorret with mutiple entries (FIRST - F, F, T, T - LAST)
    // Output - False entries removed and empty history stack
    // cout<<"*** undo untill correct with two wrong and correct entries *** "<<endl;
    // g.SetCurrentValue(9);
    // g.SetValue(0, 1);

    // g.SetCurrentValue(3);
    // g.SetValue(2, 1);

    // sol = p.GetCell(0, 0)->GetSolution();
    // g.SetCurrentValue(sol);
    // g.SetValue(0, 0);

    // sol = p.GetCell(2, 2)->GetSolution();
    // g.SetCurrentValue(sol);
    // g.SetValue(2, 2);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // g.UndoUntilCorrect();

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // UndoUntilCorret with False entires and notes
    // Output - no change in histroy stack
    // (Try with two notes, one False, and sol for same cell)
    // cout<<"*** undo untill correct with wrong entries and setting notes *** "<<endl;
    // g.SetCurrentValue(9);
    // g.SetValue(0, 1);

    // g.SetCurrentValue(3);
    // g.SetValue(2, 1);

    // g.ToggleNotesMode();
    // g.SetCurrentValue(3);
    // g.SetValue(2, 2);

    // g.SetCurrentValue(4);
    // g.SetValue(2, 2);

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // printCellData(&p, 2, 2);

    // g.UndoUntilCorrect();

    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         PrintGame(&p, i, j);
    //     }
    // }
    // cout<<"-------------------------------------"<<endl;
    // cout<<endl;

    // printCellData(&p, 2, 2);

}