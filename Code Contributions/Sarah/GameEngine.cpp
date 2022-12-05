#include <iostream>
#include "GameEngine.h"

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
        while (!tempEntry.isCorrect()) {
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
    GameEngine game;
    
    // Test Undo()
    // Undo with entry == NULL
    // Output - no change and empty history stack

    // Undo with one existing entry - value
    // Output - most recent entry in history removed and empty history stack

    // Undo with multiple existing entry - value
    // Output - most recent entry in history removed and ramianing history stack
    // (check it with value entry and notes entry)


    // Test UndoUntilCorret()
    // UndoUntilCorret with entry == NULL
    // Output - no change and empty history stack

    // UndoUntilCorret with one False entry 
    // Output - one entry removed and empty history stack
    // (make sure it loops only once)

    // UndoUntilCorret with one True entry 
    // Output - no change in histroy stack

    // UndoUntilCorret with mutiple entries (FIRST - T, T, F, F - LAST)
    // Output - False entries removed in the histroy stack

    // UndoUntilCorret with mutiple entries (FIRST - F, F, F, F - LAST)
    // Output - False entries removed and empty history stack

    // UndoUntilCorret with mutiple entries (FIRST - T, T, T, T - LAST)
    // Output - no change in histroy stack
}

