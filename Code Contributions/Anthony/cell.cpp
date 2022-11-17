using namespace std;
#include <iostream>
#include <list>

// Cell Object
class Cell {
public:
    // Data  Members
    int value;
    list<int> notes;
    bool hardWired;
    int solution;
    int row;
    int col;

    // Member Functions()
    int getSolution() 
    {
        return solution;
    }

    void setSolution(int answer)
    {
        solution = answer
    }

    int getValue()
    {
        return value;
    }

    void setValue(int val)
    {
        value = val;
    }

    bool isHardWired()
    {
        if (hardWired == true)
            return true;

        return false;
    }

    void setHardWired(bool hardWired)
    {
        hardWired = true;
    }

    void setNotes(list<int> note)
    {
        notes = note;
    }

    list<int> getNotes()
    {
        return notes;
    }

    int getRow()
    {
        return row;
    }

    int getCol()
    {
        return col;
    }

    // Constructor
    Cell(int r, int c)
    {
        row = r;
        col = c;
    }
};

// Testing Cell Object 
int main()
{
    
}