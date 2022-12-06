#include <iostream>
#include <list>
#include "cell.h"
using namespace std;

// Member Functions()
int Cell::GetSolution() 
{
    return solution;
}

void Cell::SetSolution(int answer)
{
    solution = answer;
}

int Cell::GetValue()
{
    return value;
}

void Cell::SetValue(int val)
{
    if (hardWired == true)
        cout << "Cell is hard wired!" << endl;
    else if (val < 1 || val > size)
        cout << "Invalid cell value" << endl;
    else
        value = val;
}

bool Cell::GetHardWired()
{
    if (hardWired == true)
        return true;

    return false;
}

void Cell::SetHardWired(bool hardWired)
{
    hardWired = true;
}

int * Cell::GetNotes()
{
    return notes;
}

// For testing purposes only
void Cell::SetNotes()
{
    for(int i = 0; i < 16; i++)
        notes[i] = 0;
}

void Cell::SetNotesValue(int value)
{
    if (notes[value-1] == 0)
        notes[value-1] = value;
    else
        notes[value-1] = 0;
}

// For testing purposes only
void Cell::PrintNotes()
{
    for(int i = 0; i < 16; i++)
        cout << notes[i] << " ";
    cout << endl;
}

int Cell::GetRow()
{
    return row;
}

void Cell::SetRow(int r)
{
    row = r;
}

int Cell::GetCol()
{
    return col;
}

void Cell::SetCol(int c)
{
    col = c;
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