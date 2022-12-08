class Cell
{
    public:
    // Member Functions()
    int GetSolution();
    void SetSolution(int answer);
    
    int GetValue();
    void SetValue(int val);
   
    bool GetHardWired();
    void SetHardWired(bool hardWired);
    
    int * GetNotes();
    void SetNotes();
    void SetNotesValue(int value);
    void PrintNotes();

    int GetRow();
    void SetRow(int r);

    int GetCol();
    void SetCol(int c);

    private:
    // Data  Members
    int value;
    int notes [16];
    bool hardWired;
    int solution;
    int row;
    int col;
};
