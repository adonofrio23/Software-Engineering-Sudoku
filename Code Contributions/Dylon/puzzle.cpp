using namespace std;
#include <iostream>
#include <list>
#include <iostream>
#include "cell.h"
#include "Entry.h"
#include "Entry.h"

class Puzzle {


    //We are given a row and col
    //Need to make cell object of given row and col
    //Entry Class accessible from Cell Class
    //Entry Class has a isCorrect() method
    //We will call that method
    bool isValid(int row, int col){    // What are we checking for here???
        Cell* checkCell = new Cell[row][col];
        if(checkCell.IsCorrect()){
            return true;
        }
        return false;

    }

    void setCell(Cell cell){
        int currCellRow = cell.GetRow();
        int currCellCol = cell.GetCol();
        cells[currCellRow][currCellCol] = cell;
    }

    void setSize(int sizeSet){
        size = sizeSet;
    }

    int getSize(){
        return size;
    }

    void setDifficulty(int diff){
        difficulty = diff;
    }

    int getDifficulty(){
        return difficulty;
    }

    Cell getCell(int row, int col){
        return cells[row][col];
    }
}