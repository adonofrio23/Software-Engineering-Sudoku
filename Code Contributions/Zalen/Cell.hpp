class Cell {
public:
    Cell();
    Cell(int row, int col);
    ~Cell();
    int GetValue();
    void SetValue(int val);
    int GetRow();
    int GetCol();
    void SetRow(int row);
    void SetCol(int col);
private:
    int value;
    int row;
    int col;
};

Cell::Cell() {
}

Cell::Cell(int row, int col) {
    this->row = row;
    this->col = col;
}

Cell::~Cell() {
}

int Cell::GetValue(){
    return value;
}

void Cell::SetValue(int val) {
    value = val;
}

int Cell::GetRow(){
    return row;
}

int Cell::GetCol() {
    return col;
}

void Cell::SetRow(int row) {
    this->row = row;
}

void Cell::SetCol(int col) {
    this->col = col;
}