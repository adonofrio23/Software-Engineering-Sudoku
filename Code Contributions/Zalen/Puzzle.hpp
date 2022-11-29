#include <iostream>
#include <string>

#include "Cell.hpp"

class Puzzle {
public:
	Puzzle();
	~Puzzle();
    void SetCell(Cell cell);
    Cell * GetCell(int row, int col);

private:
    Cell cells[9][9];
};

Puzzle::Puzzle() {
}

Puzzle::~Puzzle() {
}

void Puzzle::SetCell(Cell cell) {
    Cell * c = GetCell(cell.GetRow(), cell.GetCol()); // probably will need to work with pointers here
    c->SetValue(cell.GetValue());
}

Cell * Puzzle::GetCell(int row, int col) {
    return &cells[row][col];
}


