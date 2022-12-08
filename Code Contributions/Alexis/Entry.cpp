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

/// Testing Cell Object 
int main()
{
    Cell origCell;
    Cell newCell;
    Entry testEntry(origCell, newCell, false);
   
   
    newCell.InitializeNotes();
    newCell.SetNotes(5);
    newCell.SetNotes(1);
    newCell.SetNotes(15);


    newCell.SetSolution(6);
    newCell.SetValue(5);
    newCell.SetHardWired(true);
    newCell.SetRow(4);
    newCell.SetCol(3);


    cout << newCell.GetSolution() << endl;
    cout << newCell.GetValue() << endl;
    cout << newCell.GetHardWired() << endl;
    cout << newCell.GetRow() << endl;
    cout << newCell.GetCol() << endl;
    newCell.PrintNotes(); 

    cout << testEntry.isCorrect() << endl;
    cout << testEntry.GetNewCell().GetSolution() << endl;
    cout << testEntry.GetNewCell().GetValue() << endl;
    cout << testEntry.GetNewCell().GetHardWired() << endl;
    cout << testEntry.GetNewCell().GetRow() << endl;
    cout << testEntry.GetNewCell().GetCol() << endl;
}
