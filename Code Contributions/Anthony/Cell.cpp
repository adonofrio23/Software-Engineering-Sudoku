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
    Cell::value = val; 
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

void Cell::SetNotes(int value)
{
    if (Cell::notes[value-1] == 0)
        Cell::notes[value-1] = value;
    else
        Cell::notes[value-1] = 0;
}

// For testing purposes only
void Cell::InitializeNotes()
{
    for(int i = 0; i < 16; i++)
        Cell::notes[i] = 0;
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

/*
// Testing Cell Object 
int main()
{
    Cell cellTest;

    cellTest.InitializeNotes();
    cellTest.SetNotes(5);
    cellTest.SetNotes(1);
    cellTest.SetNotes(15);


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
*/