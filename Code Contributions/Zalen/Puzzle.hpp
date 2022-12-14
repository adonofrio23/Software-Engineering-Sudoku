#pragma once
#include <iostream>
#include <string>

#include "Cell.hpp"

class Puzzle{

public:
    bool isValid(int row, int col);
    void SetCell(Cell cell);
    void SetSize(int sizeSet);
    int  GetSize();
    void SetDifficulty(int diff);
    int  GetDifficulty();
    Cell * GetCell(int row, int col);
    // void LoadPuzzle(Puzzle* puzzle, int* puzzleArray);


private:
    int difficulty;
    int size;
    Cell cells[9][9];
};