#pragma once 

class Cell
{
    public:
    // Member Functions
    int GetSolution();
    void SetSolution(int answer);
    
    int GetValue();
    void SetValue(int val);
   
    bool isHardwired();
    void SetHardwired(bool h);
    
    int * GetNotes();
    void SetNotes(int index, int value);
    /*
    void InitializeNotes();
    void PrintNotes();
    */

    int GetRow();
    void SetRow(int r);

    int GetCol();
    void SetCol(int c);

    private:
    // Cell Variables
    int value;
    int notes [16];
    bool hardwired;
    int solution;
    int row;
    int col;
};
