using namespace std;
#include <iostream>
#include <list>

// Cell Object
class Cell {
public:
    // Data  Members
    int value;
    int size;
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
        solution = answer;
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

    void setSize(int s)
    {
        size = s;
    }

    int getSize() 
    {
        return size;
    }

    void setNotes()
    {
        notes = list<int> (size);
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
    // Add Notes and notes size to constructor
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