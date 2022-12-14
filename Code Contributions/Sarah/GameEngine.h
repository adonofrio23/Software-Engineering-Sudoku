#pragma once
#include <iostream>
#include "../Dylon/Puzzle.h"
#include "../Alexis/History.h"
// #include "../Anthony/Cell.h"
using namespace std;

class GameEngine {
    public:
        void SetCurrentValue(int val);
        int GetCurrentValue();
        bool SetValue(int row, int col);
        int* SetNote(int row, int col);
        void Undo();
        void UndoUntilCorrect();
        void ToggleNotesMode(); 
    	bool GetNotesMode();
        
        void SetUp(Puzzle* gamePuzzle, History* gameHistory);

    private:
        int currentValue;
        Puzzle* puzzle;
        History* history;
	    bool notesMode;
};