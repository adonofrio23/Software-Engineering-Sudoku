#include <iostream>
#include "GameEngine.h"
#include "Puzzle.h"
#include "History.h"
#include "Cell.h"

using namespace std;

// sets currentValue member variable with val parameter
void GameEngine::SetCurrentValue(int val)
{
    currentValue = val;
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
    Cell thisCellOrig = puzzle.GetCell(row, col);
    if(thisCellOrig.IsHardwired())
    {
        return false;
    }
    else
    {
        Cell thisCellNew = puzzle.GetCell(row, col);
        thisCellNew.setValue(currentValue);
        puzzle.setCell(thisCellNew);
        bool stat = puzzle.isValid(row, col);
        Entry newEntry(thisCellOrig, thisCellNew, stat);
        history.PushHistory(newEntry);
        return true;
    }
    return false;
}

/*  param row: row number of given cell
    param col: column number of given cell
    uses puzzle member object to create copy of cell object at location (row, col)
    and cell member function SetNotes to update cell variables
    returns pointer to int array of notes of the given cell
*/
int* GameEngine::SetNote(int row, int col)
{
    // based off 
    int notes[16];
    if(puzzle.isValid(row, col))
    {
        Cell thisCell = puzzle.GetCell(row, col);
        thisCell.SetNotes(notes);
    }

    return notes;
}