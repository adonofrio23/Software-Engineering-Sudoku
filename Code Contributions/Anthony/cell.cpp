#include <iostream>
#include <list>
#include "cell.h"
using namespace std;

// Member Functions()
int Cell::getSolution() 
{
    return solution;
}

void Cell::setSolution(int answer)
{
    solution = answer;
}

int Cell::getValue()
{
    return value;
}

void Cell::setValue(int val)
{
    value = val;
}

bool Cell::getHardWired()
{
    if (hardWired == true)
        return true;

    return false;
}

void Cell::setHardWired(bool hardWired)
{
    hardWired = true;
}

int * Cell::getNotes()
{
    return notes;
}

// For testing purposes only
void Cell::setNotes()
{
    for(int i = 0; i < 16; i++)
        notes[i] = 0;
}

void Cell::setNotesValue(int value)
{
    if (notes[value-1] == 0)
        notes[value-1] = value;
    else
        notes[value-1] = 0;
}

// For testing purposes only
void Cell::printNotes()
{
    for(int i = 0; i < 16; i++)
        cout << notes[i] << " ";
    cout << endl;
}

int Cell::getRow()
{
    return row;
}

void Cell::setRow(int r)
{
    row = r;
}

int Cell::getCol()
{
    return col;
}

void Cell::setCol(int c)
{
    col = c;
}

// Testing Cell Object 
int main()
{
    Cell cellTest;
   
    cellTest.setNotes();
    cellTest.setNotesValue(5);
    cellTest.setNotesValue(1);
    cellTest.setNotesValue(15);


    cellTest.setSolution(6);
    cellTest.setValue(5);
    cellTest.setHardWired(true);
    cellTest.setRow(4);
    cellTest.setCol(3);


    cout << cellTest.getSolution() << endl;
    cout << cellTest.getValue() << endl;
    cout << cellTest.getHardWired() << endl;
    cout << cellTest.getRow() << endl;
    cout << cellTest.getCol() << endl;
    cellTest.printNotes();

    
    
}