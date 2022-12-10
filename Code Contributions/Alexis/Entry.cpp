#include<iostream>
#include "Entry.h"
using namespace std;

// Constructor to create an Entry object
Entry::Entry(Cell* origCell, Cell* newCell, bool status)
{
    this->origCell = origCell;
    this->newCell = newCell;
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
    Entry testEntry(&origCell, &newCell, false);
   
   
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

    cout << testEntry.IsCorrect() << endl;
    Cell PrintCell = *testEntry.GetNewCell();
    int solution = PrintCell.GetSolution();
    cout << solution << endl;
    cout << PrintCell.GetValue() << endl;
    cout << PrintCell.GetHardWired() << endl;
    cout << PrintCell.GetRow() << endl;
    cout << PrintCell.GetCol() << endl;
    PrintCell.PrintNotes(); 
}
