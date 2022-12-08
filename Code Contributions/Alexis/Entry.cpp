using namespace std;
#include<iostream>
#include "Cell.h"
#include "Entry.h"

// Constructor to create an Entry object
Entry::Entry(Cell* origCell, Cell* newCell, bool status)
{
    origCell = origCell;
    newCell = newCell;
    isCorrect = status;
}

// Function to check if an entry is correct
bool Entry::IsCorrect()
{
    return isCorrect;
}

// Function to return the original entry in a cell
Cell* Entry::GetOrigCell()
{
    return origCell;
}

Cell* Entry::GetNewCell()
{
    return newCell;
}
