#include <iostream>
#include "Puzzle.h"




// Function prints Cell Data
void printCellData(Puzzle puzzle, int row, int col){

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*** Printing Cell Data for Cell at Row " << row+1 << " Column " << col+1 << " ***" << std::endl;
    Cell curr = puzzle.GetCell(row,col);

    std::cout << "Solution: " << curr.GetSolution() << std::endl;
    std::cout << "Value: " << curr.GetValue() << std::endl;
    std::cout << "Is it valid?: " << puzzle.isValid(row,col) << std::endl;
    std::cout << "*****************************************************" << std::endl;

}

// Function Iterates through Puzzle and calls printCellData
void printData(Puzzle puzzle){

    for(int row = 0; row < 2; row++){
        for(int col = 0; col < 2; col++){
            printCellData(puzzle,row,col);
        }
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "" << std::endl;

    Puzzle puzzle;

    puzzle.SetDifficulty(7);
    puzzle.GetDifficulty();

    puzzle.SetSize(2);
    puzzle.GetSize();

    Cell cell1;
    cell1.SetValue(2);
    cell1.SetSolution(4);
    cell1.SetRow(0);
    cell1.SetCol(0);

    Cell cell2;
    cell2.SetValue(9);
    cell2.SetSolution(9);
    cell2.SetRow(0);
    cell2.SetCol(1);

    Cell cell3;
    cell3.SetSolution(6);
    cell3.SetValue(6);
    cell3.SetRow(1);
    cell3.SetCol(0);

    Cell cell4;
    cell4.SetSolution(1);
    cell4.SetValue(1);
    cell4.SetRow(1);
    cell4.SetCol(1);


    puzzle.SetCell(cell1);
    puzzle.SetCell(cell2);
    puzzle.SetCell(cell3);
    puzzle.SetCell(cell4);


    std::cout << "Puzzle Size: " << puzzle.GetSize() << std::endl;
    std::cout << "Puzzle Difficulty: " << puzzle.GetDifficulty() << std::endl;

    printData(puzzle);





}