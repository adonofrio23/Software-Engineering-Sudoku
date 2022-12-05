#pragma once
#include <string>
#include "Puzzle.h"
#include "History.h"

class GameEngine
{
    public:
        // sets current value using parameter val, returns void
        void SetCurrentValue(int val);
        // returns the current value
        int GetCurrentValue();
        // sets the value of a particular cell, returns true if successful, false if not
        bool SetValue(int row, int col);
        // returns a random index within the range of size
        int GetRandomIndex(int size);
        // returns a hint (integer)
        int GetRandomHint();
        // undoes the last change made, returns void
        void Undo();
        // undoes every move made until the puzzle is correct, returns void
        void UndoUntilCorrect();
        // returns a puzzle created given the size and diff
        Puzzle CreateRandomPuzzle(int size, int diff);
        // returns an array of strings of every puzzle
        string* GetPuzzleList(int size, int diff);
        // returns the puzzle with the given name
        Puzzle LoadPuzzle(string puzzleName);
        // returns an array of ints of all notes in a particular cell
        int* SetNote(int row, int col);
    private:
        int currentValue;
        Puzzle puzzle;
        History history;
}