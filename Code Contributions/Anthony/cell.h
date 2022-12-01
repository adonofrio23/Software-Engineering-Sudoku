class Cell
{
    public:
    // Member Functions()
    int getSolution();
    void setSolution(int answer);
    
    int getValue();
    void setValue(int val);
   
    bool getHardWired();
    void setHardWired(bool hardWired);
    
    int * getNotes();
    void setNotes();
    void setNotesValue(int value);
    void printNotes();

    int getRow();
    void setRow(int r);

    int getCol();
    void setCol(int c);

    private:
    // Data  Members
    int value;
    int notes [16];
    bool hardWired;
    int solution;
    int row;
    int col;
};