#include <iostream>
#include "GameEngine.h"
#include "../Dylon/Puzzle.h"
#include "../Alexis/History.h"
#include "../Anthony/Cell.h"
#include "../Alexis/Entry.h"

using namespace std;

// similar to Setup (Puzzle* p, History* h)
// constructor to initialize member variables and link puzzle and history pointers from main
GameEngine::GameEngine(Puzzle* p, History* h)
{
	puzzle = p;
       	history = h;

	// initialized to zero (doesn't exist)
	currentValue = 0;
	// initialized to false by default
	notesMode = false;
}

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
    PrintHistoryStack();

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

// stub to test correct push of history stack
void GameEngine::PrintHistoryStack()
{
	cout << "History stack..." << endl;
	History* reverseStack = new History();
	while(!history->IsHistoryEmpty())
	{
		// pop top of stack and print
		Entry* entry = history->PopHistory();
		Cell* cellOrig = entry->GetOrigCell();
		Cell* cellNew = entry->GetNewCell();
		cout << "Original Entry: (" << cellOrig->GetRow() << ", " << cellOrig->GetCol() << "), val: " << cellOrig->GetValue()  <<  endl;
        cout << "New Entry: (" << cellNew->GetRow() << ", " << cellOrig->GetCol() << "), val: " << cellNew->GetValue() << "\tcorrect? ";
        if(entry->IsCorrect())
		       cout << "yes" << endl;
		else
			cout << "no" << endl;
		reverseStack->PushHistory(entry);
		cout << "------------------------------------------------------------------" << endl;
	}

	cout << "Restacking history..." << endl;
	while(!reverseStack->IsHistoryEmpty())
	{
		history->PushHistory(reverseStack->PopHistory());
	}

	return;
}


//stub for testing if pointer to puzzle is stored in GameEngine object
/*void GameEngine::PrintPuzzle()
{
	for(int r=0; r<9; r++)
	{
		for(int c=0; c<9; c++)
		{
			int v = puzzle->GetCell(r,c)->GetValue();
			cout << v << "|";
		}
		cout << endl;
	}
	return;
}*/
