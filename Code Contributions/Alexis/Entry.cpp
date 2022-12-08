using namespace std;
#include<iostream>
#include "cell.h"
#include "Entry.h"

Entry::Entry(Cell* origCell, Cell* newCell, bool status)
{
    origCell = origCell;
    newCell = newCell;
    isCorrect = status;
}

bool Entry::IsCorrect()
{
    return isCorrect;
}

Cell* Entry::GetOrigCell()
{
    return origCell;
}

Cell* Entry::GetNewCell()
{
    return newCell;
}
