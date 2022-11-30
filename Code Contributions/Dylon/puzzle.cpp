using namespace std;
#include <iostream>
#include <list>
#include <iostream>
#include "cell.h"
#include "entry.h"

class Puzzle {

    public:
        std::string difficulty;
        int size;
        Cell* cells = new Cell[size][size];


    //We are given a row and col
    //Need to make cell object of given row and col
    //Entry Class accessible from Cell Class
    //Entry Class has a isCorrect() method
    //We will call that method
    bool isValid(int row, int col){
        Cell* checkCell = new Cell[row][col]
        if(checkCell.isCorrect()){
            return true;
        }
        return false;

    }

    void setCell(Cell cell){
        currCellRow = cell.getRow()
        currCellCol = cell.getCol()
        cells[currCellRow][currCellCol] = cell
    }

    void setSize(int sizeSet){
        size = sizeSet
    }

    int getSize(){
        return size
    }

    void setDifficulty(int diff){
        difficulty = diff
    }

    int getDifficulty(){
        return difficulty
    }

    Cell getCell(int row, int col){
        return cells[row][col]
    }
}