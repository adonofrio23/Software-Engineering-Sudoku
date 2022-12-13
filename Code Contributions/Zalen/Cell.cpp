#include <iostream>
#include <list>
#include "Cell.h"
using namespace std;

// Member Functions()

// Function that returns the solution value of a cell
int Cell::GetSolution() 
{
    return Cell::solution;
}

// Function that sets the solution value of a cell
void Cell::SetSolution(int answer)
{
    Cell::solution = answer;
}

// Function that returns the inputted value of a cell non-hardwired cell
int Cell::GetValue()
{
    return Cell::value;
}

// Function that sets the inputted value of a cell non-hardwired cell
void Cell::SetValue(int val)
{
    Cell::value = val; 
}

// Function that returns whether or not a cell is hardwired
bool Cell:: isHardwired()
{
    return Cell::hardwired;
}

// Function that sets a cell to be hardwired
void Cell::SetHardwired(bool h)
{
    if (h == true)
        Cell::hardwired = true;
    else
        Cell::hardwired = false;
}

// Function that returns the integer array of notes for a cell
int * Cell::GetNotes()
{
    return Cell::notes;
}

// Function that adds or removes the inputted value to the integer array of notes for a cell
void Cell::SetNotes(int value)
{
    if (Cell::notes[value-1] == 0)
        Cell::notes[value-1] = value;
    else
        Cell::notes[value-1] = 0;
}

// For testing purposes only. Initializes the integer array of notes for a cell to all 0s.
void Cell::InitializeNotes()
{
    for(int i = 0; i < 16; i++)
        Cell::notes[i] = 0;
}

// For testing purposes only. Prints out the integer array of notes for a cell.
void Cell::PrintNotes()
{
    for(int i = 0; i < 16; i++)
        cout << Cell::notes[i] << " ";
    cout << endl;
}

// Returns the row value of a cell
int Cell::GetRow()
{
    return Cell::row;
}

// Sets the row value of a cell
void Cell::SetRow(int r)
{
    Cell::row = r;
}

// Returns the column value of a cell
int Cell::GetCol()
{
    return Cell::col;
}

// Sets the column value of a cell
void Cell::SetCol(int c)
{
    Cell::col = c;
}
