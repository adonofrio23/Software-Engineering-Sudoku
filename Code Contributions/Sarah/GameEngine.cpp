#include <iostream>
#include "GameEngine.h"
#include "Puzzle.h"
#include "History.h"
#include "Entry.h"
using namespace std;


void GameEngine::Undo() {
    // pop the latest entry in history
    Entry entry = history.PopHistory();

    // check if history stack is empty
    if (entry == NULL) {
        return;
    } else {
        // set the cell back to the original cell
        puzzle.SetCell(entry.GetOrigCell());
    }
}

void GameEngine::UndoUntilCorrect() {
    // pop the latest entry in history 
    Entry tempEntry = history.PopHistory();

    // check if history stack is empty
    if (tempEntry != NULL) {

        // if isCorrect() == false then go into while loop
        while (!tempEntry.IsCorrect()) {
            // set the cell back to the original cell
            puzzle.SetCell(tempEntry.GetOrigCell());

            // pop another entry from history to check 
            tempEntry = history.PopHistory();
            
            if (tempEntry == NULL) {
                return;
            }
        }
        // if isCorrect() == true then it will push back the history and exit
        history.PushHistory(tempEntry);
        return;
    }
}

// Test 
int main() {
    GameEngine g;
    Puzzle p;
    
    // Test Undo()
    // Undo with entry == NULL
    // Output - no change and empty history stack
    g.Undo();
    cout<<"The game did not crash with no change."<<endl;
    

    // Undo with one existing entry - value
    // Output - most recent entry in history removed and empty history stack
    g.SetCurrentValue(5);
    g.SetValue(0, 0);
    cout<<"0, 0: 5"<<endl;
    g.Undo();
    ans = p.GetCell(0, 0).GetValue();
    if (ans == 0) {
        cout<<"0, 0: "<<ans<<"     Test: Pass"<<endl;
    } else {
        cout<<ans<<"     Test: Fail"<<endl;
    }

    // Undo with multiple existing entry - value
    // Output - most recent entry in history removed and ramianing history stack
    g.SetCurrentValue(5);
    g.SetValue(0, 0);
    g.SetCurrentValue(9);
    g.SetValue(0, 0);
    cout<<"0, 0: 5  9"<<endl;
    g.Undo();
    ans = p.GetCell(0, 0).GetValue();
    if (ans == 5) {
        cout<<"0, 0: "<<ans<<"     Test: Pass"<<endl;
    } else {
        cout<<ans<<"     Test: Fail"<<endl;
    }

    // One entry on stack
    g.Undo();

    // Undo with multiple existing entry - notes
    // Output - most recent entry in history removed and ramianing history stack
    // g.SetCurrentValue(9);
    // g.SetNote(2, 2);
    // review how to SetNote with note value


    // Test UndoUntilCorret()
    // UndoUntilCorret with entry == NULL
    // Output - no change and empty history stack
    g.UndoUntilCorrect();
    cout<<"The game did not crash with no change."<<endl;


    // UndoUntilCorret with one False entry 
    // Output - one entry removed and empty history stack
    // (make sure it loops only once)
    g.SetCurrentValue(4);
    g.SetValue(2, 2);
    g.UndoUntilCorrect();
    ans = p.GetCell(2, 2).GetValue();
    if (ans == 0) {
        cout<<"2, 2: "<<ans<<"     Test: Pass"<<endl;
    } else {
        cout<<ans<<"     Test: Fail"<<endl;
    }

    // UndoUntilCorret with one True entry 
    // Output - no change in histroy stack
    // test it with notes or solutions

    // UndoUntilCorret with mutiple entries (FIRST - T, T, F, F - LAST)
    // Output - False entries removed in the histroy stack
    // create True entries with notes or solutions
    g.SetCurrentValue(4);
    g.SetValue(2, 2);
    g.SetCurrentValue(6);
    g.SetValue(2, 2);
    ans = p.GetCell(2, 2).GetValue();
    if (ans == 0) {
        cout<<"2, 2: "<<ans<<"    Test: Pass"<<endl;
    } else {
        cout<<ans<<"     Test: Fail"<<endl;
    }

    // UndoUntilCorret with mutiple entries (FIRST - F, F, F, F - LAST)
    // Output - False entries removed and empty history stack
    g.SetCurrentValue(4);
    g.SetValue(2, 2);
    g.SetCurrentValue(6);
    g.SetValue(2, 2);
    g.SetCurrentValue(8);
    g.SetValue(2, 2);
    g.SetCurrentValue(3);
    g.SetValue(2, 2);
    ans = p.GetCell(2, 2).GetValue();
    if (ans == 0) {
        cout<<"2, 2: "<<ans<<"    Test: Pass"<<endl;
    } else {
        cout<<ans<<"     Test: Fail"<<endl;
    }

    // UndoUntilCorret with mutiple entries (FIRST - T, T, T, T - LAST)
    // Output - no change in histroy stack

}

