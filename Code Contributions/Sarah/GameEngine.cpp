#include <iostream>
#include "GameEngine.h"
// #include "./../Alexis/Entry.h"
// #include "../Amanda/GameEngine.cpp"
using namespace std;


// Undo the most recent move
void GameEngine::Undo() {
    // check if history stack is empty
    if (!history->IsHistoryEmpty()) {
        cout<<"undo"<<endl;

        // pop the latest entry in history
        Entry* entry = history->PopHistory();

        // set the cell back to the original cell
        Cell* origCell = entry->GetOrigCell();

        puzzle->SetCell(*origCell);
    }
}

// Undo every move until the whole puzzle is valid/correct
void GameEngine::UndoUntilCorrect() {
    // check if history stack is empty
    if (!history->IsHistoryEmpty()) {

        // pop the latest entry in history 
        Entry* tempEntry = history->PopHistory();

        // if isCorrect() == false then keep undoing
        while (!tempEntry->IsCorrect()) {
            // set the cell back to the original cell
            puzzle->SetCell(*(tempEntry->GetOrigCell()));

            // if history is empty then exit
            if (history->IsHistoryEmpty()) {
                return;
            } else {
                // if not, pop another entry from history to check 
                tempEntry = history->PopHistory();
            }
        }

        // if isCorrect() == true then it will push back the history and exit
        history->PushHistory(tempEntry);
    }
}

void GameEngine::SetUp(Puzzle* gamePuzzle, History* gameHistory) {
    puzzle = gamePuzzle;
    history = gameHistory;
}


// Unit Testing 
int main() {
    
}





