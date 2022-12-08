#include "HelperFunctions.h"

bool LoopOverPuzzle(Puzzle* puzzle, void (*func)(Puzzle*, int, int, bool*))
{
    bool b;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
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
    g->SetCell(2, 2);
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
    g->SetCell(0, 2);
    ans = p->GetCell(0, 2)->GetValue();
    testResult = false;
    if (ans == 4) testResult = true;
    std::cout << "Set then get hard-wired puzzle location|";
    std::cout << "          4      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Writing a bad value
    g->SetCurrentValue(10);
    g->SetCell(0, 0);
    ans = p->GetCell(0, 0)->GetValue();
    testResult = false;
    if (ans == 0) testResult = true;
    std::cout << "Set then get with a bad value          |";
    std::cout << "          0      | ";
    std::cout << "       " << ans << "     |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";
    //     Writing a bad value
    g->SetCurrentValue(5);
    g->SetCell(9, 9);
    ans = p->GetCell(9, 9)->GetValue();
    testResult = false;
    if (ans == 0) testResult = true;
    std::cout << "Set at a bad location                  |";
    std::cout << "         -1      | ";
    std::cout << " " << ans << "  |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";

    // Get/Set Note(s)
    std::cout << "_________________________________________________________________________________\n";
    //     setting single note
    g->ToggleNotesMode();
    g->SetCurrentValue(3);
    g->SetCell(2, 2);
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
    g->SetCell(2, 2);
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
    g->SetCell(2, 2);
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
    g->SetCell(2, 2);
    g->SetCurrentValue(9);
    g->SetCell(2, 2);
    g->UndoLastMove();
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
    g->SetCell(2, 2);
    g->ToggleNotesMode();
    g->SetCurrentValue(9);
    g->SetCell(2, 2);
    g->UndoLastMove();
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
    g->SetCell(2, 2);
    g->SetCurrentValue(9);
    g->SetCell(2, 2);
    g->UndoLastMove();
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
    g->SetCell(2, 2);
    g->UndoLastMove();
    ans = p->GetCell(2, 2)->GetNotes()[2];
    testResult = false;
    if (ans == 3) testResult = true;
    std::cout << "Undo set value to previous note        |";
    std::cout << "          3      | ";
    std::cout << "       " << ans << "      |";
    if (testResult) std::cout << "     Pass\n";
    else std::cout << "     Fail\n";

    // Hint
    std::cout << "_________________________________________________________________________________\n";
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
}