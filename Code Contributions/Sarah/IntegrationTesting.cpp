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

// Added note printing to Dylon's testing function
void printCellData(Puzzle* puzzle, int randomRow, int randomCol){

    cout << "" << std::endl;
    cout << "* Printing Cell Data for Cell at Row " << randomRow << " Column " << randomCol << " *" << std::endl;
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

void testAlgorithms(){
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

    cout<<"========================================="<<endl;
    cout<<endl;

    GameEngine g(&p, &h);

    cout<<"------------Algorithms test------------"<<endl;
    cout<<endl;

    cout<<"*******Testing FindAllEmpty()*******"<<endl;
    vector<Cell* > empty = alg.FindAllEmpty(&p);
    cout << "Original, Size of Empty: " << empty.size() << endl;
    g.SetCurrentValue(9);
    g.SetValue(0, 1);
    empty = alg.FindAllEmpty(&p);
    cout << "With one cell with value, Size of Empty: " << empty.size() << endl;
    cout<<endl;

    cout<<"*******Testing SolveBruteForce()*******"<<endl;
    // Set solutions
    alg.SolveBruteForce(&p);

    // Check if solutions are set
    cout<<"Solution of 0, 0: "<<p.GetCell(0,0)->GetSolution()<<endl;
    cout<<"Solution of 0, 1: "<<p.GetCell(0,1)->GetSolution()<<endl;

    cout<<endl;

    cout<<"*******Testing FindAllErrors*******"<<endl;
    // Setting 0,1 to correct cell to test 
    g.SetCurrentValue(p.GetCell(0,1)->GetSolution());
    g.SetValue(0, 1);

    vector<Cell*> errors = alg.FindAllErrors(&p);
    cout << "Original, Size of Errors: " << errors.size() << endl;

    // Set 2 erros
    g.SetCurrentValue(9);
    g.SetValue(0, 1);
    g.SetCurrentValue(3);
    g.SetValue(2, 1);
    
    errors = alg.FindAllErrors(&p);
    cout << "After setting two errors, Size of Errors: " << errors.size() << endl;
    cout<<endl;

    cout<<"*******Testing RankDifficulty*******"<<endl;
    int rank = alg.RankDifficulty(&p);
}

void testSettingValue() {
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

    cout<<"========================================="<<endl;
    cout<<endl;

    GameEngine g(&p, &h);

    // Set solutions
    alg.SolveBruteForce(&p);

    cout<<"----------Test: setting a value in puzzle cell---------"<<endl;
    // Set an illegal value to a illegal location
    cout<<"*** illegal value in illegal location ***"<<endl;
    g.SetCurrentValue(40);
    g.SetValue(4, 50);
    cout<<"Output: No change to puzzle"<<endl;

    cout<<"========================================="<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"========================================="<<endl;
    cout<<endl;

    // Set a legal value to an illegal location
    cout<<"*** legal value in illegal location ***"<<endl;
    g.SetCurrentValue(3);
    g.SetValue(3, 15);
    cout<<"Output: No change to puzzle"<<endl;
    cout<<"========================================="<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"========================================="<<endl;
    cout<<endl;


    // Set a legal value to a legal location
    cout<<"*** legal value in legal location ***"<<endl;
    cout<<"Output: One cell(0, 0) filled in puzzle"<<endl;
    g.SetCurrentValue(3);
    g.SetValue(0, 0);

    cout<<"========================================="<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"========================================="<<endl;
    cout<<endl;
    // Undo for next test
    g.Undo();

    // Set a legal value to a hard-wired location
    cout<<"*** legal value to a hard-wired location ***"<<endl;
    g.SetCurrentValue(5);
    g.SetValue(0, 2);
    cout<<"Output: No change to puzzle"<<endl;
    cout<<"========================================="<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"========================================="<<endl;
    cout<<endl;
}

void testSettingNote() {
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

    cout<<"========================================="<<endl;
    cout<<endl;

    GameEngine g(&p, &h);

    // Set solutions
    alg.SolveBruteForce(&p);

    // Test for setting a note in a puzzle cell
    cout<<"----------Test: setting a note in puzzle cell---------"<<endl;

    // Set an illegal note to a legal location
    cout<<"***** illegal note to a legal location *****"<<endl;
    printCellData(&p, 2, 2);

    g.ToggleNotesMode();
    g.SetCurrentValue(20);
    g.SetNote(2, 2);

    cout<<"Output: No change to cell data";
    printCellData(&p, 2, 2);
    // The current val 5 gets set into the note from the last test's value

    // Set a legal note to a legal location
    cout<<"**** legal note to a legal location *****"<<endl;
    printCellData(&p, 0, 1);
    g.SetCurrentValue(2);
    g.SetNote(0, 1);

    cout<<"Output: Note added to cell data";
    printCellData(&p, 0, 1);
    cout<<endl;

    // Set a legal note to a hard-wired location
    cout<<"*** legal note to a hard-wired location ***"<<endl;
    printCellData(&p, 0, 2);

    g.SetCurrentValue(2);
    g.SetNote(0, 2);

    cout<<"Output: ";
    printCellData(&p, 0, 2);
    cout<<endl;

    // Add a note to a cell with existing note
    cout<<"*** add a note to a cell with existing note ***"<<endl;
    printCellData(&p, 0, 2);

    g.SetCurrentValue(3);
    g.SetNote(0, 2);

    g.SetCurrentValue(4);
    g.SetNote(0, 2);

    cout<<"Output: Note added to cell data";
    printCellData(&p, 0, 2);

}

void testUndoingMoves() {
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

    cout<<"========================================="<<endl;
    cout<<endl;

    GameEngine g(&p, &h);

    // Set solutions
    alg.SolveBruteForce(&p);

    // Test for undoing moves
    cout<<"----------Test: undoing moves---------"<<endl;

    // Undo with entry == NULL
    // Output - no change and empty history stack

    cout<<"*** undo when no move has been made *** "<<endl;

    g.Undo();

    cout<<"Output: The game did not crash with no change."<<endl;
    cout<<"========================================="<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"========================================="<<endl;
    cout<<endl;


    // Undo with one existing entry - value
    // Output - most recent entry in history removed and empty history stack
    cout<<"*** undo with one move *** "<<endl;

    g.SetCurrentValue(5);
    g.SetValue(0, 0);
    cout<<"Value set at 0,0"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }

    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    g.Undo();

    cout<<"Output: No value at 0, 0"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }

    cout<<"-------------------------------------"<<endl;
    cout<<endl;


    // Undo with multiple existing entry - value
    // Output - most recent entry in history removed and ramianing history stack
    cout<<"*** undo with multiple moves on one cell *** "<<endl;

    g.SetCurrentValue(5);
    g.SetValue(0, 0);
    g.SetCurrentValue(9);
    g.SetValue(0, 0);

    cout<<"Cell 0,0 set to 5 and then 9"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }

    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    g.Undo();

    cout<<"Output: 0,0 set to 5"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }

    cout<<"-------------------------------------"<<endl;
    cout<<endl;


    // One entry on stack
    g.Undo();

    // Undo with multiple existing entry - notes
    // Output - most recent entry in history removed and ramianing history stack
    cout<<"*** undo with multiple note moves on one cell *** "<<endl;
    printCellData(&p, 0, 0);

    g.ToggleNotesMode();
    g.SetCurrentValue(2);
    g.SetValue(0, 0);

    g.SetCurrentValue(3);
    g.SetValue(0, 0);

    cout<<"Cell notes 2 and 3 added"<<endl;
    printCellData(&p, 0, 0);

    g.Undo();
    
    cout<<"Output: Cell notes 3"<<endl;
    printCellData(&p, 0, 0);

    g.Undo();
    g.ToggleNotesMode();

    // Test UndoUntilCorret()
    // UndoUntilCorret with entry == NULL
    // Output - no change and empty history stack
    cout<<"*** undo untill correct with no moves *** "<<endl;
    g.UndoUntilCorrect();
    cout<<"The game did not crash with no change."<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }

    cout<<"-------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;

    // UndoUntilCorret with multiple False entries
    // Output - one entry removed and empty history stack
    cout<<"*** undo untill correct with multiple wrong entries *** "<<endl;
    g.SetCurrentValue(5);
    g.SetValue(0, 0);
    g.SetCurrentValue(4);
    g.SetValue(2, 2);

    cout<<"Wrong entries for (0,0) and (2,2)"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    g.UndoUntilCorrect();

    cout<<"Output: Wrong entries undone"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    // UndoUntilCorret with mutiple True entries
    // Output - no change in histroy stack
    cout<<"*** undo untill correct with multiple correct entries *** "<<endl;
    int sol = p.GetCell(0, 0)->GetSolution();
    g.SetCurrentValue(sol);
    g.SetValue(0, 0);

    sol = p.GetCell(2, 2)->GetSolution();
    g.SetCurrentValue(sol);
    g.SetValue(2, 2);

    cout<<"Correct entries for (0,0) and (2,2)"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    g.UndoUntilCorrect();

    cout<<"Output: No changes to correct cells"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    // UndoUntilCorret with mutiple entries (FIRST - T, T, F, F - LAST)
    // Output - False entries removed in the histroy stack

    cout<<"*** undo untill correct with two correct and wrong entries *** "<<endl;
    // stack already has two T entries
    g.SetCurrentValue(9);
    g.SetValue(0, 1);
    g.SetCurrentValue(3);
    g.SetValue(2, 1);
    cout<<"T(0,0) - T(0,0) - F(0,1) - F(2,1)"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    g.UndoUntilCorrect();

    cout<<"Output: T(0,0) - T(0,0)"<<endl;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    // Two T 
    g.Undo();
    g.Undo();

    // UndoUntilCorret with mutiple entries (FIRST - F, F, T, T - LAST)
    // Output - False entries removed and empty history stack
    cout<<"*** undo untill correct with two wrong and correct entries *** "<<endl;
    g.SetCurrentValue(9);
    g.SetValue(0, 1);

    g.SetCurrentValue(3);
    g.SetValue(2, 1);

    sol = p.GetCell(0, 0)->GetSolution();
    g.SetCurrentValue(sol);
    g.SetValue(0, 0);

    sol = p.GetCell(2, 2)->GetSolution();
    g.SetCurrentValue(sol);
    g.SetValue(2, 2);

    cout<<"F(0,1) - F(2,1) - T(0,0) - T(2,2)"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    g.UndoUntilCorrect();

    cout<<"Output: No moves"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    // UndoUntilCorret with False entires and notes
    // Output - no change in histroy stack
    // (Try with two notes, one False, and sol for same cell)
    cout<<"*** undo untill correct with wrong entries and setting notes *** "<<endl;
    g.SetCurrentValue(9);
    g.SetValue(0, 1);

    g.SetCurrentValue(3);
    g.SetValue(2, 1);

    g.ToggleNotesMode();
    g.SetCurrentValue(3);
    g.SetValue(2, 2);

    g.SetCurrentValue(4);
    g.SetValue(2, 2);

    cout<<"Wrong entires for (0,1) and (2,1) and notes 3, 4 at (2,2)"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    printCellData(&p, 2, 2);

    g.UndoUntilCorrect();
    
    cout<<"Output: No moves"<<endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            PrintGame(&p, i, j);
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

    printCellData(&p, 2, 2);
}

// Test 
int main() {

    testAlgorithms();

    testSettingValue();

    testSettingNote();

    testUndoingMoves();

}