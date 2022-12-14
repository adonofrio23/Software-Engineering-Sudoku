using namespace std;

#include "Puzzle.h"


    //Function will check value against solution in Cell
    bool Puzzle::isValid(int row, int col){
        Cell* checkCell = GetCell(row,col);
        int val = checkCell->GetValue();
        int sol = checkCell->GetSolution();
        if(val == sol){
            return true;
        }
        return false;
    }

    // Function will set a cell in the puzzle
    void Puzzle::SetCell(Cell cell){
        int currCellRow = cell.GetRow();
        int currCellCol = cell.GetCol();

        cells[currCellRow][currCellCol] = cell;

    }

    // Function will set the size for the puzzle
    void Puzzle::SetSize(int sizeSet){
        size = sizeSet;
    }

    // Function will return the size of the puzzle
    int Puzzle::GetSize(){
        return size;
    }

    // Function will set the difficulty
    void Puzzle::SetDifficulty(int diff){
        difficulty = diff;
    }

    // Function will get the difficulty
    int Puzzle::GetDifficulty(){
        return difficulty;
    }

    // Function will return a pointer to a cell object
    Cell* Puzzle::GetCell(int row, int col){
        return &cells[row][col];
    }
