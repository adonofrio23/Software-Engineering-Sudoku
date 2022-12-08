using namespace std;
#include<iostream>
#include "Cell.h"

class Entry{
    public:
    Entry(Cell* origCell, Cell* newCell, bool status);
    bool IsCorrect();
    Cell* GetOrigCell();
    Cell* GetNewCell();

    private:
    Cell* origCell;
    bool isCorrect;
    Cell* newCell;
   
};


