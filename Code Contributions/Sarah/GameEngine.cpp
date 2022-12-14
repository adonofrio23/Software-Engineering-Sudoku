#include <iostream>
#include "GameEngine.h"
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


void GameEngine::SetUp(Puzzle* gamePuzzle, History* gameHistory) {
    puzzle = gamePuzzle;
    history = gameHistory;
    currentValue = 0;
    notesMode = false;
}



// Amanda's code
// sets currentValue member variable with val parameter
void GameEngine::SetCurrentValue(int val)
{
    // check if val is in range
    if(val > 0 && val <= 9)
    {
	// set currentValue
	currentValue = val;
    }
    else
    {
	cout << "Invalid value!" << endl;
    }
    return;
}


// returns currentValue member variable
int GameEngine::GetCurrentValue()
{
    return currentValue;
}

/*  param row: row of the given cell
    param col: column of the given cell
    gets cell at given row and column, sets the value of the cell in the puzzle
    creates a new entry with the cell's updated information and pushes it to the stack
    returns true if value is successfully set in the given cell
    returns false if value cannot be set in the given cell
*/
bool GameEngine::SetValue(int row, int col)
{
    // check if row and col values are within range, leave function and return false if not
    if(row < 0 || row >= 9 || col < 0 || col >= 9)
    {
	    cout << "Invalid cell!" << endl;
	    return false;
    }

    // check if currentValue exists (once currentValue is set via SetCurrentValue, it exists)
    if(currentValue == 0)
    {
	    cout << "Please set the value first!" << endl;
	    return false;
    }

    // get cell to set
    Cell* thisCell = puzzle->GetCell(row, col);
    // make a copy of original cell
    Cell* origCell = new Cell();
    origCell->SetRow(row);
    origCell->SetCol(col);
    origCell->SetValue(thisCell->GetValue());
    origCell->SetSolution(thisCell->GetSolution());

    // check if cell is hardwired
    if(thisCell->isHardwired())
    {
	    cout << "Invalid cell!" << endl;
	    return false;
    }
    origCell->SetHardwired(false);

    if(notesMode)
    {
	    // if in notes mode, erase value and set note
        thisCell->SetValue(0);
        if(thisCell->GetNotes()[currentValue - 1] == 0)
        {
            thisCell->SetNotes(currentValue-1, currentValue);
        }
        else
        {
            thisCell->SetNotes(currentValue-1, 0);
        }
    }
    else
    {
        // if not in notes mode, set value and erase notes
        thisCell->SetValue(currentValue);
        int* notesArray = thisCell->GetNotes();
        for(int i=0;i<16;i++)
        {
            notesArray[i] = 0;
        }
    }

    // set cell
    puzzle->SetCell(*thisCell);
    // output for purpose of checking pointer storage
    // cout << "Original Cell value: " << origCell->GetValue() << endl;
    // cout << "New Cell value: " << thisCell->GetValue() << endl;
    
    // get if cell is valid
    bool stat = puzzle->isValid(row, col);
    
    // check if history stack is empty
    if(history->IsHistoryEmpty())
    {
        Entry* newEntry =  new Entry(origCell, thisCell, stat);
        history->PushHistory(newEntry);	
    }
    else
    {	
    	// pop from history stack to get most recent puzzle stat
    	Entry* entry = history->PopHistory();
    	// Entry* entry = history->TopOfStack();

        // if puzzle is incorrect, next entry is incorrect regardless of correctness of currentValue
        if(entry->IsCorrect())
    	{
        	Entry* newEntry = new Entry(origCell, thisCell, stat);
        	history->PushHistory(entry);
        	history->PushHistory(newEntry);
    	}
    	else{
        	Entry* newEntry= new Entry(origCell, thisCell, false);
        	history->PushHistory(entry);
        	history->PushHistory(newEntry);
    	}
    }
    // PrintHistoryStack();

    return true;
}

/*  param row: row number of given cell
    param col: column number of given cell
    uses puzzle member object to get pointer to cell object at location (row, col)
    and cell member function SetNotes to update cell member variables
    returns pointer to int array of notes of the given cell
*/
int* GameEngine::SetNote(int row, int col)
{
    Cell* thisCell = puzzle->GetCell(row, col);
    thisCell->SetNotes(currentValue-1, currentValue);
    return thisCell->GetNotes();
}

// toggle value of notesMode bool member variable
void GameEngine::ToggleNotesMode()
{
	// toggle notesMode member variable
	if(notesMode)
	{
		notesMode = false;
		// output for testing purposes
		// cout << "You are now in regular mode" << endl;
	}
	else
	{
		notesMode = true;
		// output for testing purposes
		// cout << "You are now in notes mode" << endl;
	}
    return;
}

//returns value of notesMode member variable
bool GameEngine::GetNotesMode()
{
	return notesMode;
}


// int EvilPuzzle[] = {0,0,4, 5,0,1, 9,0,0,
//                        0,2,0, 0,8,0, 0,3,0,
//                        6,0,0, 0,0,0, 0,0,5,
//                        0,0,8, 7,0,6, 3,0,0,
//                        0,5,0, 0,0,0, 0,9,0,
//                        0,0,3, 4,0,8, 5,0,0,
//                        3,0,0, 0,0,0, 0,0,9,
//                        0,8,0, 0,7,0, 0,6,0,
//                        0,0,2, 8,0,5, 1,0,0   };

//     int EvilPuzzleSolution[] = {8,3,4, 5,6,1, 9,2,7,
//                                 7,2,5, 9,8,4, 6,3,1,
//                                 6,1,9, 2,3,7, 4,8,5,
//                                 1,9,8, 7,5,6, 3,4,2,
//                                 4,5,6, 1,2,3, 7,9,8,
//                                 2,7,3, 4,9,8, 5,1,6,
//                                 3,4,7, 6,1,2, 8,5,9,
//                                 5,8,1, 3,7,9, 2,6,4,
//                                 9,6,2, 8,4,5, 1,7,3   };

//     void LoadGame(Puzzle * puzzle, int r, int c){

//     Cell cell;
//     cell.SetRow(r);
//     cell.SetCol(c);
//     cell.SetValue(EvilPuzzle[r * 9 + c]);
//     if (cell.GetValue() != 0) {
//         cell.SetHardwired(true);
//         cell.SetSolution(cell.GetValue());
//     }
//     else {
//         // cell.SetSolution(0);
//         cell.SetHardwired(false);
//         cell.SetSolution(EvilPuzzleSolution[r * 9 + c]);
//     }
//     for (int i = 0; i < 9; i++) {
//         cell.GetNotes()[i] = 0;
//     }
//     puzzle->SetCell(cell);
//     return;
//     }


// // Unit Testing (not using other GameEngine functions)
// int main() {
//     // Test Undo()
//     Puzzle p;
//     History h;
//     GameEngine g;


//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             LoadGame(&p, i, j);
//         }
//     }
    
//     // Undo with empty History
//     // Output - no change to the puzzle with empty histroy stack
//     // g.Undo();
//     // cout<<"The game did not crash with no change."<<endl;


//     // Undo with one existing entry - value
//     // Output - no change to the puzzle with empty history stack
//     //          (most recent entry in history removed)
    
//     Cell* cellPtr = p.GetCell(0, 0);

//     cellPtr->SetSolution(9);
//     cellPtr->SetValue(0);
//     cellPtr->SetHardwired(false);

//     cout<<"0, 0: 0 ";
//     cout<<"0, 0: "<<cellPtr->GetValue()<<endl;

//     Cell origCell;
//     Cell newCell;
//     bool status = true;
   
//     origCell.SetSolution(9);
//     origCell.SetValue(0);
//     origCell.SetHardwired(false);
//     origCell.SetRow(0);
//     origCell.SetCol(0);

//     newCell.SetSolution(9);
//     newCell.SetValue(9);
//     newCell.SetHardwired(false);
//     newCell.SetRow(0);
//     newCell.SetCol(0);

//     Entry entry(&origCell, &newCell, status);

//     p.SetCell(newCell);

//     h.PushHistory(&entry);

//     cout<<"0, 0: 9 ";
//     cout<<"0, 0: "<<cellPtr->GetValue()<<endl;

//     g.Undo();

//     cout<<"0, 0: 0 ";
//     cout<<"0, 0: "<<cellPtr->GetValue()<<endl;

// }
