// LoadPrintPuzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int EvilPuzzle[] = {   0,0,4, 5,0,1, 9,0,0,
                       0,2,0, 0,8,0, 0,3,0,
                       6,0,0, 0,0,0, 0,0,5,
                       0,0,8, 7,0,6, 3,0,0,
                       0,5,0, 0,0,0, 0,9,0,
                       0,0,3, 4,0,8, 5,0,0,
                       3,0,0, 0,0,0, 0,0,9,
                       0,8,0, 0,7,0, 0,6,0,
                       0,0,2, 8,0,5, 1,0,0   };
class Cell
{
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

Cell::Cell()
{
}

Cell::Cell(int row, int col)
{
    this->row = row;
    this->col = col;
}

Cell::~Cell()
{
}

int Cell::GetValue()
{
    return value;
}

void Cell::SetValue(int val)
{
    value = val;
}

int Cell::GetRow()
{
    return row;
}

int Cell::GetCol()
{
    return col;
}

void Cell::SetRow(int row)
{
    this->row = row;
}

void Cell::SetCol(int col)
{
    this->col = col;
}

class Puzzle
{
public:
	Puzzle();
	~Puzzle();
    void SetCell(Cell cell);
    Cell * GetCell(int row, int col);
private:
    Cell cells[9][9];
};

Puzzle::Puzzle()
{
}

Puzzle::~Puzzle()
{
}

void Puzzle::SetCell(Cell cell)
{
    Cell * c = GetCell(cell.GetRow(), cell.GetCol()); // probably will need to work with pointers here
    c->SetValue(cell.GetValue());
}

Cell * Puzzle::GetCell(int row, int col)
{
    return &cells[row][col];
}

void PrintGame(Puzzle puzzle)
{
    std::cout << "\n";
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            int v = puzzle.GetCell(r, c)->GetValue();
            if ((c == 0) || (c == 3) || (c == 6)) {
                std::cout << "||";
                if (v != 0) std::cout << ' ' << v << ' ';
                else std::cout << "   ";
            }
            else {
                std::cout << "|";
                if (v != 0) std::cout << ' ' << v << ' ';
                else std::cout << "   ";
            }
        }
        std::cout << "||\n";
        if ((r == 2) || (r == 5)) std::cout << "||===|===|===||===|===|===||===|===|===||\n";
        else if (r != 8) std::cout << "||---|---|---||---|---|---||---|---|---||\n";
    }
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";

}




int main()
{
    std::cout << "Hello Team C++!\n -3 % 12 = "  << -3%12 <<"\n";
    Puzzle puzzle;
    Cell cell;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cell.SetRow(r);
            cell.SetCol(c);
            cell.SetValue(EvilPuzzle[r*9+c]);
            puzzle.SetCell(cell);
        }
    }

    Cell * pCell;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            pCell = puzzle.GetCell(r,c);
            std::cout << pCell->GetValue() << ',';
        }
        std::cout << "\n";
    }
    PrintGame(puzzle);

}
