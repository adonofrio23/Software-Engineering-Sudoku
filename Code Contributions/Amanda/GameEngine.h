#pragma once
#include <string>
#include "../Dylon/Puzzle.h"
#include "../Alexis/History.h"
#include "../Alexis/Entry.h"
#include "../Anthony/Cell.h"


class GameEngine
{
    public:
	    // constructor
        GameEngine(Puzzle* p, History* h);
        // sets current value using parameter val, returns void
        void SetCurrentValue(int val);
        // returns the current value
        int GetCurrentValue();
        // sets the value of a particular cell, returns true if successful, false if not
        bool SetValue(int row, int col);
        //void Undo();
        //void UndoUntilCorrect();
        int* SetNote(int row, int col);
        void ToggleNotesMode(); 
    	bool GetNotesMode();
    private:
        int currentValue;
        Puzzle* puzzle;
        History* history;
	    bool notesMode;
};
