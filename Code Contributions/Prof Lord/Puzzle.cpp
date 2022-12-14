#include "Puzzle.hpp"
using namespace std;
//This method will check value against solution in Cell
bool Puzzle::isValid(int row, int col) {
    Cell* checkCell = GetCell(row, col);
    int val = checkCell->GetValue();
    int sol = checkCell->GetSolution();
    if (val == sol) {
        return true;
    }
    return false;
}

void Puzzle::SetCell(Cell cell) {
    int currCellRow = cell.GetRow();
    int currCellCol = cell.GetCol();

    Cell* c = GetCell(cell.GetRow(), cell.GetCol());
    c->SetValue(cell.GetValue());
    c->SetRow(cell.GetRow());
    c->SetCol(cell.GetCol());
    c->SetHardwired(cell.isHardwired());
    c->SetSolution(cell.GetSolution());
    for (int i = 0; i < 9; i++) {
        (c->GetNotes())[i] = (cell.GetNotes())[i];
    }

}

void Puzzle::SetSize(int sizeSet) {
    size = sizeSet;
}

int Puzzle::GetSize() {
    return size;
}

void Puzzle::SetDifficulty(int diff) {
    difficulty = diff;
}

int Puzzle::GetDifficulty() {
    return difficulty;
}

Cell* Puzzle::GetCell(int row, int col) {
    return &cells[row][col];
}

