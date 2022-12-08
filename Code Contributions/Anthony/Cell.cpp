#include <iostream>
#include <list>
#include "Cell.h"
using namespace std;

// Member Functions()
int Cell::GetSolution() 
{
    return Cell::solution;
}

void Cell::SetSolution(int answer)
{
    Cell::solution = answer;
}

int Cell::GetValue()
{
    return Cell::value;
}

void Cell::SetValue(int val)
{
    /*
    if (Cell::hardWired == true)
        cout << "Cell is hard wired!" << endl;
    else if (val < 1 || val > size)
        cout << "Invalid cell value" << endl;
    else
        Cell::value = val; */
}

bool Cell::GetHardWired()
{
    return Cell::hardWired;
}

void Cell::SetHardWired(bool hardWired)
{
    Cell::hardWired = true;
}

int * Cell::GetNotes()
{
    return Cell::notes;
}

// For testing purposes only
void Cell::SetNotes()
{
    for(int i = 0; i < 16; i++)
        Cell::notes[i] = 0;
}

void Cell::SetNotesValue(int value)
{
    if (Cell::notes[value-1] == 0)
        Cell::notes[value-1] = value;
    else
        Cell::notes[value-1] = 0;
}

// For testing purposes only
void Cell::PrintNotes()
{
    for(int i = 0; i < 16; i++)
        cout << Cell::notes[i] << " ";
    cout << endl;
}

int Cell::GetRow()
{
    return Cell::row;
}

void Cell::SetRow(int r)
{
    Cell::row = r;
}

int Cell::GetCol()
{
    return Cell::col;
}

void Cell::SetCol(int c)
{
    Cell::col = c;
}

// Testing Cell Object 
int main()
{
    Cell cellTest;
   
    cellTest.SetNotes();
    cellTest.SetNotesValue(5);
    cellTest.SetNotesValue(1);
    cellTest.SetNotesValue(15);


    cellTest.SetSolution(6);
    cellTest.SetValue(5);
    cellTest.SetHardWired(true);
    cellTest.SetRow(4);
    cellTest.SetCol(3);


    cout << cellTest.GetSolution() << endl;
    cout << cellTest.GetValue() << endl;
    cout << cellTest.GetHardWired() << endl;
    cout << cellTest.GetRow() << endl;
    cout << cellTest.GetCol() << endl;
    cellTest.PrintNotes();

    
    
}
