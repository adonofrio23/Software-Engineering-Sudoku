#include <iostream>
#include "GameEngine.h"
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

int EvilPuzzle[] = {0,0,4, 5,0,1, 9,0,0,
                       0,2,0, 0,8,0, 0,3,0,
                       6,0,0, 0,0,0, 0,0,5,
                       0,0,8, 7,0,6, 3,0,0,
                       0,5,0, 0,0,0, 0,9,0,
                       0,0,3, 4,0,8, 5,0,0,
                       3,0,0, 0,0,0, 0,0,9,
                       0,8,0, 0,7,0, 0,6,0,
                       0,0,2, 8,0,5, 1,0,0   };

    int EvilPuzzleSolution[] = {8,3,4, 5,6,1, 9,2,7,
                                7,2,5, 9,8,4, 6,3,1,
                                6,1,9, 2,3,7, 4,8,5,
                                1,9,8, 7,5,6, 3,4,2,
                                4,5,6, 1,2,3, 7,9,8,
                                2,7,3, 4,9,8, 5,1,6,
                                3,4,7, 6,1,2, 8,5,9,
                                5,8,1, 3,7,9, 2,6,4,
                                9,6,2, 8,4,5, 1,7,3   };

    void LoadGame(Puzzle * puzzle, int r, int c){

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


// Unit Testing (not using other GameEngine functions)
int main() {
    // Test Undo()
    Puzzle p;
    History h;
    GameEngine g;


    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            LoadGame(&p, i, j);
        }
    }
    
    // Undo with empty History
    // Output - no change to the puzzle with empty histroy stack
    // g.Undo();
    // cout<<"The game did not crash with no change."<<endl;


    // Undo with one existing entry - value
    // Output - no change to the puzzle with empty history stack
    //          (most recent entry in history removed)
    
    Cell* cellPtr = p.GetCell(0, 0);

    cellPtr->SetSolution(9);
    cellPtr->SetValue(0);
    cellPtr->SetHardwired(false);

    cout<<"0, 0: 0 ";
    cout<<"0, 0: "<<cellPtr->GetValue()<<endl;

    Cell origCell;
    Cell newCell;
    bool status = true;
   
    origCell.SetSolution(9);
    origCell.SetValue(0);
    origCell.SetHardwired(false);
    origCell.SetRow(0);
    origCell.SetCol(0);

    newCell.SetSolution(9);
    newCell.SetValue(9);
    newCell.SetHardwired(false);
    newCell.SetRow(0);
    newCell.SetCol(0);

    Entry entry(&origCell, &newCell, status);

    p.SetCell(newCell);

    h.PushHistory(&entry);

    cout<<"0, 0: 9 ";
    cout<<"0, 0: "<<cellPtr->GetValue()<<endl;

    g.Undo();

    cout<<"0, 0: 0 ";
    cout<<"0, 0: "<<cellPtr->GetValue()<<endl;

}





