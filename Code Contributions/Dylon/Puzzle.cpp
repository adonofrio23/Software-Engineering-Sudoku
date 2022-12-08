using namespace std;
#include <iostream>
#include <list>
#include <iostream>
#include "Cell.h"
#include "Entry.h"
#include "Entry.h"

class Puzzle {


    //We are given a row and col
    //Need to make cell object of given row and col
    //Entry Class accessible from Cell Class
    //Entry Class has a isCorrect() method
    //We will call that method
    bool Puzzle::isValid(int row, int col){    // What are we checking for here???
        Cell* checkCell = new Cell[row][col];
        if(checkCell.IsCorrect()){
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

    Cell Puzzle::GetCell(int row, int col){
        return cells[row][col];
    }
}
