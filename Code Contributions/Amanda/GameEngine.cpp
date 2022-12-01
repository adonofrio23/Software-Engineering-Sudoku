#include <iostream>
#include "GameEngine.h"
#include "Puzzle.h"
#include "History.h"
#include "Cell.h"

using namespace std;

// default constructor
GameEngine::GameEngine()
{
    // intentionally empty
}

GameEngine::GameEngine(int thisValue)
{
    currentValue = thisValue;
}

GameEngine::GameEngine(int thisValue, Puzzle thisPuzzle, History thisHistory)
{
    currentValue =  thisValue;
    puzzle = thisPuzzle;
    history = thisHistory;
}

void GameEngine::SetCurrentValue(int val)
{
    currentValue = val;
}

int GameEngine::GetCurrentValue()
{
    return currentValue;
}

// bool returns based off of
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