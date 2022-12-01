class Cell
{
    public:
    // Data Members
    int value;
    int size;
    list<int> notes;
    bool hardWired;
    int solution;
    int row;
    int col;
    
     // Member Functions()
    int getSolution() 
    void setSolution(int answer)
   
    int getValue()
    void setValue(int val)
   

    bool isHardWired()
    void setHardWired(bool hardWired)
  
    void setSize(int s)
    int getSize() 

    void setNotes()
    list<int> getNotes()

    int getRow()
    int getCol()
   
    // Constructor
    // Add Notes and notes size to constructor
    Cell(int r, int c)
    
};