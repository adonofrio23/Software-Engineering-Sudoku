// main driver program with full integration
// initially used as amanda's "unit" testing since game engine was reliant on representation team
// then added to to fully integrate 
#include <iostream>
#include <vector>
#include "GameEngine.h"
#include "../Alexis/Entry.h"
#include "../Alexis/History.h"
#include "../Anthony/Cell.h"
#include "../Dylon/Puzzle.h"
#include "../Dina/Algorithms.h"

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

int MediumPuzzle[] = { 0,7,9, 0,4,0, 5,0,0,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,0,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 0,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };

int EasyPuzzle[] = {   0,7,9, 8,4,0, 5,1,3,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,9,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 7,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };

void PrintGame(Puzzle * puzzle, int r, int c, bool * b)
{
    int v = puzzle->GetCell(r, c)->GetValue();
    if ((c == 0) || (c == 3) || (c == 6)) {
        std::cout << "||";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    else {
        std::cout << "|";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    if (c == 8) {
        std::cout << "||\n";
        if ((r == 2) || (r == 5)) std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        else if (r != 8) std::cout << "||---|---|---||---|---|---||---|---|---||\n";
    }
    return;
}

void PrintSolution(Puzzle* puzzle, int r, int c, bool* b)
{
    int v = puzzle->GetCell(r, c)->GetSolution();
    if ((c == 0) || (c == 3) || (c == 6)) {
        std::cout << "||";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    else {
        std::cout << "|";
        if (v != 0) std::cout << ' ' << v << ' ';
        else std::cout << "   ";
    }
    if (c == 8) {
        std::cout << "||\n";
        if ((r == 2) || (r == 5)) std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        else if (r != 8) std::cout << "||---|---|---||---|---|---||---|---|---||\n";
    }
    return;
}

void LoadGame(Puzzle * puzzle, int r, int c, bool *b)
{
    Cell cell;
    cell.SetRow(r);
    cell.SetCol(c);
    cell.SetValue(EasyPuzzle[r * 9 + c]);
    if (cell.GetValue() != 0) {
        cell.SetHardwired(true);
        cell.SetSolution(cell.GetValue());
    }
    else {
        cell.SetSolution(0);
        cell.SetHardwired(false);
    }
    for (int i = 0; i < 9; i++) {
        cell.GetNotes()[i] = 0;
    }
    puzzle->SetCell(cell);
    return;
}

bool LoopOverPuzzle(Puzzle* puzzle, void (*func)(Puzzle*, int, int, bool*))
{
    bool b;
    puzzle->SetSize(9);
    for (int r = 0; r < puzzle->GetSize(); r++) {
        for (int c = 0; c < puzzle->GetSize(); c++) {
            func(puzzle, r, c, &b);
        }
    }
    return b;
}

void RunTestSuite(Puzzle* p, History* h, GameEngine* g) {
    std::cout << "\n\nIntegration testing for the Sudoku puzzle solver.\n";
    std::cout << "Test description                       | Expected result | Actual result | Pass/Fail/Crash\n";
    std::cout << "_________________________________________________________________________________\n";
    // Set/Get value
    //     Writing to an empty cell
    g->SetCurrentValue(5);
    g->SetValue(2, 2);
    int ans = p->GetCell(2, 2)->GetValue();
    bool testResult = false;
    if (ans == 5) testResult = true;
    std::cout << "Set then get empty puzzle location     |";
    std::cout << "          5      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Writing to a hard-wired cell
    g->SetCurrentValue(5);
    g->SetValue(0, 2);
    ans = p->GetCell(0, 2)->GetValue();
    testResult = false;
    if (ans == 9) testResult = true;
    std::cout << "Set then get hard-wired puzzle location|";
    std::cout << "          9      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Writing a bad value
    g->SetCurrentValue(10);
    g->SetValue(0, 0);
    ans = p->GetCell(0, 0)->GetValue();
    testResult = false;
    if (ans == 0) testResult = true;
    std::cout << "Set then get with a bad value          |";
    std::cout << "          0      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Writing a bad value
    g->SetCurrentValue(5);
    g->SetValue(9, 9);
    ans = p->GetCell(9, 9)->GetValue();
    testResult = false;
    if (ans == 0) testResult = true;
    std::cout << "Set at a bad location                  |";
    std::cout << "         -1      | ";
    std::cout << " \t  " << ans << "  \t |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";

    // Get/Set Note(s)
    std::cout << "_________________________________________________________________________________\n";
    //     setting single note
    g->ToggleNotesMode();
    g->SetCurrentValue(3);
    g->SetValue(2, 2);
    ans = p->GetCell(2, 2)->GetNotes()[2];
    testResult = false;
    if (ans == 3) testResult = true;
    std::cout << "Set then get single note               |";
    std::cout << "          3      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     setting multi-note
    g->SetCurrentValue(9);
    g->SetValue(2, 2);
    ans = p->GetCell(2, 2)->GetNotes()[2];
    int ans2 = p->GetCell(2, 2)->GetNotes()[8];
    testResult = false;
    if ((ans == 3) && (ans2 == 9)) testResult = true;
    std::cout << "Set a second note in same cell         |";
    std::cout << "         3,0     | ";
    std::cout << "      " << ans << "," << ans2 << "     |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     reset note
    g->SetCurrentValue(9);
    g->SetValue(2, 2);
    ans = p->GetCell(2, 2)->GetNotes()[2];
    ans2 = p->GetCell(2, 2)->GetNotes()[8];
    testResult = false;
    if ((ans == 3) && (ans2 == 0)) testResult = true;
    std::cout << "Reset a note in a cell                 |";
    std::cout << "         3,0     | ";
    std::cout << "      " << ans2 << "," << ans << "     |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    g->ToggleNotesMode();

    // Undo
    std::cout << "_________________________________________________________________________________\n";
    //     Undo setting value
    g->SetCurrentValue(5);
    g->SetValue(2, 2);
    g->SetCurrentValue(9);
    g->SetValue(2, 2);
    g->Undo();
    ans = p->GetCell(2, 2)->GetValue();
    testResult = false;
    if (ans == 5) testResult = true;
    std::cout << "Undo setting of last value entry       |";
    std::cout << "          5      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Undo until correct
    g->UndoUntilCorrect();
    ans = p->GetCell(2, 2)->GetValue();
    testResult = false;
    if (ans == 0) testResult = true;
    std::cout << "Undo until correct                     |";
    std::cout << "          0      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Undo setting note to value entry
    g->SetCurrentValue(5);
    g->SetValue(2, 2);
    g->ToggleNotesMode();
    g->SetCurrentValue(9);
    g->SetValue(2, 2);
    g->Undo();
    ans = p->GetCell(2, 2)->GetValue();
    testResult = false;
    if (ans == 5) testResult = true;
    std::cout << "Undo set note to previous value        |";
    std::cout << "          5      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Undo setting note to previous note
    g->SetCurrentValue(3);
    g->SetValue(2, 2);
    g->SetCurrentValue(9);
    g->SetValue(2, 2);
    g->Undo();
    ans = p->GetCell(2, 2)->GetNotes()[8];
    ans2 = p->GetCell(2, 2)->GetNotes()[2];
    testResult = false;
    if ((ans == 0) && (ans2 ==3)) testResult = true;
    std::cout << "Undo set note to previous note         |";
    std::cout << "         3,0     | ";
    std::cout << "      " << ans2 << "," << ans << "     |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Undo setting value to previous note
    g->ToggleNotesMode();
    g->SetCurrentValue(5);
    g->SetValue(2, 2);
    g->Undo();
    ans = p->GetCell(2, 2)->GetNotes()[2];
    testResult = false;
    if (ans == 3) testResult = true;
    std::cout << "Undo set value to previous note        |";
    std::cout << "          3      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";

    // Hint
    /*std::cout << "_________________________________________________________________________________\n";
    //     Getting hint at specific location
    g->UndoUntilCorrect();  // Clear any prior incorrect testing results
    g->GetSpecificHint(2, 2);
    ans = p->GetCell(2, 2)->GetValue();
    testResult = false;
    if (ans == 9) testResult = true;
    std::cout << "Get hint at specific location          |";
    std::cout << "          9      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Getting hint at random error location
    for (int i = 0; i < 3; i++) {
        g->SetCurrentValue(9);
        g->SetCell(8, 8);
        g->SetCell(8, 7);
        g->SetCell(7, 8);
        g->GetRandomHint();
    }
    testResult = false;
    if ((p->GetCell(8, 8)->GetValue() == 3) && (p->GetCell(8, 7)->GetValue() == 7) && (p->GetCell(7, 8)->GetValue() == 4))
        testResult = true;
    std::cout << "Get random hint to remove an error     |";
    std::cout << "         !9      | ";
    std::cout << "       ?      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Getting hint at random empty location
    int emptyCellsBefore = 0;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (p->GetCell(row, col)->GetValue() == 0) emptyCellsBefore++;
        }
    }
    g->GetRandomHint();
    testResult = false;
    int emptyCellsAfter = 0;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (p->GetCell(row, col)->GetValue() == 0) emptyCellsAfter++;
        }
    }
    if (emptyCellsBefore == ++emptyCellsAfter)
        testResult = true;
    std::cout << "Get random hint to replace empty entry |";
    std::cout << "          ?      | ";
    std::cout << "       ?      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";

    // Stack fixed after hint
    std::cout << "_________________________________________________________________________________\n";
    //     Fixing stack after hint changes an existing entry to correct value
    g->SetCurrentValue(9);
    g->SetCell(0,7);
    g->SetCell(0, 8);
    g->SetCell(1, 8);
    g->GetSpecificHint(0, 8);
    g->UndoUntilCorrect();
    testResult = false;
    if ((p->GetCell(0, 7)->GetValue() == 0) && (p->GetCell(0, 8)->GetValue() == 7) && (p->GetCell(1, 8)->GetValue() == 0))
        testResult = true;
    std::cout << "History fixed after hint operation     |";
    std::cout << "          ?      | ";
    std::cout << "       ?      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    */
}

int main()
{
    Puzzle puzzle;
    History history;
    Algorithms algorithm;

    LoopOverPuzzle(&puzzle, &LoadGame);

    GameEngine engine(&puzzle, &history); 
    // Pretty print the puzzle
    std::cout << "\n";
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";
    LoopOverPuzzle(&puzzle, &PrintGame);
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";

    cout << "Puzzle Difficulty ";
    int val = algorithm.RankDifficulty(&puzzle);

    bool isSolved = algorithm.SolveBruteForce(&puzzle);

    // Get user/programmer input for testing
    bool done = false;
    char command;
    int row = 0, col = 0;
    while (!done) 
    {
        // c++ team did not make hint or load puzzle functions
        cout << "Command: (u)ndo, (U)ndo until correct, Set current (v)alue, (s)et cell, (n)ote mode toggle, (r)un test suite, (q)uit: ";
        std::cin >> command;
        switch (command) 
        {
            case 'q':
                done = true;
                break;
            case 'u':
                engine.Undo();
                break;
            case 'U':
                engine.UndoUntilCorrect();
                break;
            case 'v':
                cout << "Enter value: ";
                int val;
                cin >> val;
                engine.SetCurrentValue(val);
                //cout << engine.GetCurrentValue();
                break;
            case 's':
                cout << "Enter row: ";
                cin >> row;
                cout << "Enter column: ";
                cin >> col;
                engine.SetValue(row, col);
                break;
            case 'n':
                engine.ToggleNotesMode();
                break;
            case 'r':
                RunTestSuite(&puzzle, &history, &engine);
                break;
            default:
                break;
        }

        if (!engine.GetNotesMode()) 
	    {
            // Pretty print the puzzle
            std::cout << "\n";
            std::cout << "||===|===|===||===|===|===||===|===|===||\n";
            LoopOverPuzzle(&puzzle, &PrintGame);
            std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        }
        else 
	    {
            // Pretty print notes for last cell selected
            Cell* cell = puzzle.GetCell(row, col);
            for (int i = 0; i < 9; i++) {
                std::cout << cell->GetNotes()[i];
                if (i != 8) std::cout << ", ";
            }
            std::cout << "\n";
        }
    }

    cout <<  "\nCorrect Puzzle: " << endl;
    std::cout << "\n";
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";
    LoopOverPuzzle(&puzzle, &PrintSolution);
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";

    cout << "----------------------------------------------------" << endl;
    vector<Cell*> empty = algorithm.FindAllEmpty(&puzzle);
    cout << "Number of Empty Cells: " << empty.size() << endl;
    cout << "All Empty Cells in the Puzzle" << endl;
    for (int f = 0; f < empty.size(); f++)
    {
        cout << "Row: " << empty.at(f)->GetRow() << " Col: " << empty.at(f)->GetCol()
        << " Val: " << empty.at(f)->GetValue() << endl;
    }
    cout << "----------------------------------------------------" << endl;


    cout << "----------------------------------------------------" << endl;
    vector<Cell*> error1 = algorithm.FindAllErrors(&puzzle);
    cout << "Number of errors: " << error1.size() << endl;
    cout << "All Errors in the puzzle: " << endl;
    for (int f = 0; f < error1.size(); f++)
    {
        cout << "Row: " << error1.at(f)->GetRow() << " Col: " << error1.at(f)->GetCol() << " Val: " << error1.at(f)->GetValue() << endl;
    }
    cout << "----------------------------------------------------" << endl;


    return 0;
}
