#include "../Anthony/Cell.h"
#pragma once

class Puzzle{

public:
    bool isValid(int row, int col);
    void SetCell(Cell cell);
    void SetSize(int sizeSet);
    int  GetSize();
    void SetDifficulty(int diff);
    int  GetDifficulty();
    Cell* GetCell(int row, int col);


private:
    int difficulty;
    int size;
    Cell cells[16][16];
};