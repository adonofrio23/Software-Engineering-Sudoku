#include <iostream>
#include "GameEngine.h"
#include "../Dylon/Puzzle.h"
#include "../Alexis/History.h"
#include "../Anthony/Cell.h"
#include "../Alexis/Entry.h"

using namespace std;

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
    if(val > 0 && val <= 9)
    {
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
    Cell* origCell = puzzle->GetCell(row, col);

    // check if cell is hardwired
    if(thisCell->isHardwired())
    {
	    cout << "Invalid cell!" << endl;
	    return false;
    }
    
    if(notesMode)
    {
	    // if in notes mode, erase value and set note
	    thisCell->SetValue(0);
	    SetNote(row, col);
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

    puzzle->SetCell(*thisCell);
    //check values of pointer to cell objects
    cout << "Original Cell value: " << origCell->GetValue() << endl;
    cout << "New Cell value: " << thisCell->GetValue() << endl;
        /*thisCellNew->SetValue(currentValue);
        puzzle->SetCell(*thisCellNew);
        //bool stat = puzzle->isValid(row, col);
        Entry* entry = history->PopHistory();
        if(entry->IsCorrect())
        {
            Entry* newEntry = new Entry(thisCellOrig, thisCellNew, stat);
            history->PushHistory(entry);
            history->PushHistory(newEntry);
	}
        else{
            Entry* newEntry =  new Entry(thisCellOrig, thisCellNew, false);
            history->PushHistory(entry);
            history->PushHistory(newEntry);
	}
	
        return true;
    }
    */
    return true;
}

/*  param row: row number of given cell
    param col: column number of given cell
    uses puzzle member object to create copy of cell object at location (row, col)
    and cell member function SetNotes to update cell variables
    returns pointer to int array of notes of the given cell
*/
int* GameEngine::SetNote(int row, int col)
{
    Cell* thisCell = puzzle->GetCell(row, col);
    thisCell->SetNotes(currentValue);
    return thisCell->GetNotes();
}

void GameEngine::ToggleNotesMode()
{
	// toggle notesMode member variable
	if(notesMode)
	{
		notesMode = false;
		cout << "You are now in regular mode" << endl;
	}
	else
	{
		notesMode = true;
		cout << "You are now in notes mode" << endl;
	}

        return;
}

bool GameEngine::GetNotesMode()
{
	return notesMode;
}

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
