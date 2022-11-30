#include <iostream>
#include "GameEngine.h"

using namespace std;


void GameEngine::Undo() {
    // pop the latest entry in history
    Entry entry = history.PopHistory();

    if (entry == NULL) {
        exit; 
    } else {
        // set the cell back to the original cell
        puzzle.SetCell(entry.GetOrigCell());
    }
}

void GameEngine::UndoUntilCorrect() {
    // pop the latest entry in history 
    Entry tempEntry = history.PopHistory();

    if (tempEntry != NULL) {
        // if isCorrect() == false then go into while loop
        while (!tempEntry.isCorrect()) {
            // set the cell back to the original cell
            puzzle.SetCell(tempEntry.GetOrigCell());
            // pop the SetCell of the previous line - check SetCell implementation in Puzzle
            history.PopHistory();
            // pop another entry from history to check 
            tempEntry = history.PopHistory();
            
            if (tempEntry == NULL) {
                exit;
            }
        }
        // if isCorrect() == true then it will push back the history and exit
        history.PushHistory(tempEntry);
    }
}

