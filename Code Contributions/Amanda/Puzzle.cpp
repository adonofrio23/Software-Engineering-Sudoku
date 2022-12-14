using namespace std;

#include "Puzzle.h"
#include "../Anthony/Cell.h"

    //This method will check value against solution in Cell
    bool Puzzle::isValid(int row, int col){
        // get cell now returns a pointer to a cell object
        Cell* checkCell = GetCell(row,col);
        // cell member functions called with -> operator
        int val = checkCell->GetValue();
        int sol = checkCell->GetSolution();
        if(val == sol){
            return true;
        }
        return false;
    }

    void Puzzle::SetCell(Cell cell){
        int currCellRow = cell.GetRow();
        int currCellCol = cell.GetCol();

        cells[currCellRow][currCellCol] = cell;

    }

    void Puzzle::SetSize(int sizeSet){
        size = sizeSet;
    }

    int Puzzle::GetSize(){
        return size;
    }

    void Puzzle::SetDifficulty(int diff){
        difficulty = diff;
    }

    int Puzzle::GetDifficulty(){
        return difficulty;
    }

    // now returns a pointer to a cell object
    Cell* Puzzle::GetCell(int row, int col){
        // return the address of this cell 
	    return &cells[row][col];
    }

