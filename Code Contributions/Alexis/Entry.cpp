#include<iostream>
#include "Entry.h"
#include "History.h"
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

// // Testing Cell Object 
// int main()
// {
//     Cell origCell;
//     Cell newCell;
//     bool status = false;
//     Entry testEntry(&origCell, &newCell, status);
   
//     // Testing Original Cell
//     origCell.InitializeNotes();
//     origCell.SetNotes(6);
//     origCell.SetNotes(7);
//     origCell.SetNotes(2);

//     origCell.SetSolution(8);
//     origCell.SetValue(9);
//     origCell.SetHardwired(false);
//     origCell.SetRow(1);
//     origCell.SetCol(8);

//     cout << "Testing Original Cell" << endl;
//     cout << origCell.GetSolution() << endl;
//     cout << origCell.GetValue() << endl;
//     cout << origCell.isHardwired() << endl;
//     cout << origCell.GetRow() << endl;
//     cout << origCell.GetCol() << endl;
//     origCell.PrintNotes(); 
//     cout << endl;

//     cout << "Testing Original Cell within Entry. Should be the same as above." << endl;
//     Cell PrintOrigCell = *testEntry.GetOrigCell();
//     cout << PrintOrigCell.GetSolution() << endl;
//     cout << PrintOrigCell.GetValue() << endl;
//     cout << PrintOrigCell.isHardwired() << endl;
//     cout << PrintOrigCell.GetRow() << endl;
//     cout << PrintOrigCell.GetCol() << endl;
//     PrintOrigCell.PrintNotes(); 
//     cout << endl;
    
//     // Testing New Cell
//     newCell.InitializeNotes();
//     newCell.SetNotes(5);
//     newCell.SetNotes(1);
//     newCell.SetNotes(15);

//     newCell.SetSolution(6);
//     newCell.SetValue(5);
//     newCell.SetHardwired(true);
//     newCell.SetRow(4);
//     newCell.SetCol(3);

//     cout << "Testing New Cell" << endl;
//     cout << newCell.GetSolution() << endl;
//     cout << newCell.GetValue() << endl;
//     cout << newCell.isHardwired() << endl;
//     cout << newCell.GetRow() << endl;
//     cout << newCell.GetCol() << endl;
//     newCell.PrintNotes(); 
//     cout << endl;

//     cout << "Testing New Cell within Entry. Should be the same as above." << endl;
//     Cell PrintNewCell = *testEntry.GetNewCell();
//     cout << PrintNewCell.GetSolution() << endl;
//     cout << PrintNewCell.GetValue() << endl;
//     cout << PrintNewCell.isHardwired() << endl;
//     cout << PrintNewCell.GetRow() << endl;
//     cout << PrintNewCell.GetCol() << endl;
//     PrintNewCell.PrintNotes(); 
//     cout << endl;
    
//     cout << "Testing IsCorrect() method" << endl;
//     cout << testEntry.IsCorrect() << endl;
// }
