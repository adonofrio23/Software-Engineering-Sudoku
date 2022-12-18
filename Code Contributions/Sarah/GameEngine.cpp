#include <iostream>
#include "./../Dylon/Puzzle.h"
#include "./../Alexis/History.h"
#include "./../Anthony/Cell.h"
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

// // Unit test for Undo and UndoUntilCorrect
// int main() {
//     History history; 
//     Puzzle puzzle;
    
//     cout<<"------------Unit Testing-----------"<<endl;

//     cout<<"** Testing Undo() with empty history **"<<endl;
//     cout<<"Input: None"<<endl;
//     // Unable to call Undo without creating game engine
//     // so just copied the code of Undo()
//     if (!history.IsHistoryEmpty()) {
//         Entry* entry = history.TopOfStack();
//         Cell* origCell = entry->GetOrigCell();
//         puzzle.SetCell(*origCell);
//         history.PopHistory();
//     }

//     cout<<"Output: No crash and no change"<<endl;
//     cout<<endl;

//     cout<<"** Testing Undo() with not empty history **"<<endl;

//     // pushing two entries to history
//     cout<<"Input: Two enties in history stack (value 1 - value 2)"<<endl;
//     Cell origCell1;
//     Cell newCell1;
//     bool stat1 = false;
    
//     origCell1.SetValue(1);
//     Entry entry1(&origCell1, &newCell1, stat1);
//     history.PushHistory(&entry1);

//     Cell origCell2;
//     Cell newCell2;
//     bool stat2 = false;

//     origCell2.SetValue(2);
//     Entry entry2(&origCell2, &newCell2, stat2);
//     history.PushHistory(&entry2);

//     // Undoing and printing values
//     cout<<"Output: ";
//     if (!history.IsHistoryEmpty()) {
//         Entry* entry = history.TopOfStack();
//         Cell* origCell = entry->GetOrigCell();
//         puzzle.SetCell(*origCell);
//         Entry* popped = history.PopHistory();
//         cout<<"popped value "<<popped->GetOrigCell()->GetValue()<<", ";
//     }

//     cout<<"value from history stack entry "<<history.TopOfStack()->GetOrigCell()->GetValue()<<endl;
//     cout<<endl;

//     // Undoing one more time for next test
//     if (!history.IsHistoryEmpty()) {
//         Entry* entry = history.TopOfStack();
//         Cell* origCell = entry->GetOrigCell();
//         puzzle.SetCell(*origCell);
//         Entry* popped = history.PopHistory();
//     }


//     cout<<"** Testing UndoUntilCorrect() with empty history **"<<endl;
//     cout<<"Input: None"<<endl;
//     // UndoUntilCorrect()
//     if (!history.IsHistoryEmpty()) {
//         Entry* tempEntry = history.TopOfStack();
//         while (!tempEntry->IsCorrect()) {
//             Cell* origCell = tempEntry->GetOrigCell();
//             puzzle.SetCell(*origCell);
//             history.PopHistory();
//             if (history.IsHistoryEmpty()) {
//                 break;
//             } else {
//                 tempEntry = history.TopOfStack();
//             }
//         }
//     }
//     cout<<"Output: No crash and no change"<<endl;
//     cout<<endl;

//     cout<<"** Testing UndoUntilCorrect() with not empty history **"<<endl;

//     // pushing 3 entryes with one true and two false 
//     cout<<"Input: ";
//     Cell origCell3;
//     Cell newCell3;
//     bool stat3 = true;
    
//     origCell3.SetValue(1);
//     Entry entry3(&origCell3, &newCell3, stat3);
//     history.PushHistory(&entry3);
//     cout<<"value 1 true entry, ";

//     origCell1.SetValue(2);
//     history.PushHistory(&entry1);
//     cout<<"value 2 false entry, ";

//     origCell2.SetValue(3);
//     history.PushHistory(&entry2);
//     cout<<"value 3 false entry pushed"<<endl;

//     // Undoing until correct with printing values
//     cout<<"Output: ";
//     if (!history.IsHistoryEmpty()) {
//         Entry* tempEntry = history.TopOfStack();
//         while (!tempEntry->IsCorrect()) {
//             Cell* origCell = tempEntry->GetOrigCell();
//             puzzle.SetCell(*origCell);
//             Entry* popped = history.PopHistory();

//             cout<<popped->GetOrigCell()->GetValue()<<" popped "<<endl;
//             if (history.IsHistoryEmpty()) {
//                 break;
//             } else {
//                 tempEntry = history.TopOfStack();
//             }
//         }
//     }

//     cout<<"value from history stack entry "<<history.TopOfStack()->GetOrigCell()->GetValue()<<endl;
//     cout<<endl;

//     return 0;
// }
