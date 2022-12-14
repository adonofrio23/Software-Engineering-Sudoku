#pragma once
// #include "Puzzle.hpp"
// #include "Cell.hpp"
// #include "History.hpp"
#include "Algorithms.hpp"
#include "History.hpp"

class GameEngine {
public:
    // void Setup(Puzzle* puzzle, History* history);
    void UndoLastMove();
    void UndoUntilCorrect();
    void SetCurrentValue(int val);
    void SetCell(int row, int col);
    void SetNote(int row, int col);
    void GetSpecificHint(int row, int col);
    void GetRandomHint();
    void ToggleNotesMode();
    bool GetNotesMode();
    void LoadPuzzle();
private:
    Puzzle* puzzle;
    // History* history;
    int currentValue;
    bool notesMode;
};
