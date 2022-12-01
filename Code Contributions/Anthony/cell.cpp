using namespace std;
#include <iostream>
#include <list>

// Cell Object
class Cell {
public:
    // Data  Members
    int value;
    int size;
    int notes [16];
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

    void setNotes(int value)
    {
        if (notes[value-1] = 0)
            notes[value-1] = value;
        else
            notes[value-1] = 0;
    }

    int * getNotes()
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

};

// Testing Cell Object 
int main()
{
    
}