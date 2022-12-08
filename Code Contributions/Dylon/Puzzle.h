class Puzzle{

    public:
    bool isValid(int row, int col);
    void setCell(Cell cell);
    void setSize(int sizeSet);
    int getSize();
    void setDifficulty(int diff);
    int getDifficulty();
    Cell getCell(int row, int col);


    private:
    int difficulty;
    int size;
    Cell* cells = new Cell[size][size];


};