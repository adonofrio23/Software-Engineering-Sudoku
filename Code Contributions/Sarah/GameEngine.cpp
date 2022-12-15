#include <iostream>
#include "../Amanda/GameEngine.h"
using namespace std;


// Undo the most recent move
void GameEngine::Undo() {
    // check if history stack is empty
    if (!history->IsHistoryEmpty()) {

        // get the latest entry in history
        Entry* entry = history->TopOfStack();
        // set the cell back to the original cell
        Cell* origCell = entry->GetOrigCell();
        puzzle->SetCell(*origCell);
        
        // pop it from history stack
        history->PopHistory();
    }
}

// Undo every move until the whole puzzle is valid/correct
void GameEngine::UndoUntilCorrect() {
    // check if history stack is empty
    if (!history->IsHistoryEmpty()) {

        // get the latest entry in history 
        Entry* tempEntry = history->TopOfStack();

        // if isCorrect() == false then keep undoing
        while (!tempEntry->IsCorrect()) {
            // set the cell back to the original cell
            Cell* origCell = tempEntry->GetOrigCell();
            puzzle->SetCell(*origCell);

            // pop the stack from history
            history->PopHistory();
            // if history is empty then exit
            if (history->IsHistoryEmpty()) {
                return;
            } else {
                // if not, pop another entry from history to check 
                tempEntry = history->TopOfStack();
            }
        }
    }
}


// void GameEngine::SetUp(Puzzle* gamePuzzle, History* gameHistory) {
//     puzzle = gamePuzzle;
//     history = gameHistory;
//     currentValue = 0;
//     notesMode = false;
// }
