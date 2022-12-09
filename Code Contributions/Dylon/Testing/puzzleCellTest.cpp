#include <iostream>
#include "Puzzle.h"

int EvilPuzzle[] = {   0,0,4, 5,0,1, 9,0,0,
                       0,2,0, 0,8,0, 0,3,0,
                       6,0,0, 0,0,0, 0,0,5,
                       0,0,8, 7,0,6, 3,0,0,
                       0,5,0, 0,0,0, 0,9,0,
                       0,0,3, 4,0,8, 5,0,0,
                       3,0,0, 0,0,0, 0,0,9,
                       0,8,0, 0,7,0, 0,6,0,
                       0,0,2, 8,0,5, 1,0,0   };

void LoadGame(Puzzle* puzzle, int r, int c)
{
    Cell cell;
    cell.SetRow(r);
    cell.SetCol(c);
    cell.SetValue(EvilPuzzle[r * 9 + c]);
    if (cell.GetValue() != 0) {
        cell.SetHardWired(true);
        cell.SetSolution(cell.GetValue());
    }
    else {
        cell.SetSolution(0);
        cell.SetHardWired(false);
    }

    puzzle->SetCell(cell);
    return;
}

void printPuzzle(Puzzle puzzle, int rowSize, int colSize){

    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++) {

            Cell curr = puzzle.GetCell(row,col);
            std::cout << curr.GetSolution() << " ";
        }
        std::cout << "" << std::endl;
    }
}

void printCellData(Puzzle puzzle, int randomRow, int randomCol){

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*** Printing Cell Data for Cell at Row " << randomRow+1 << " Column " << randomCol+1 << " ***" << std::endl;
    Cell curr = puzzle.GetCell(randomRow,randomCol);

    std::cout << "Solution: " << curr.GetSolution() << std::endl;
    std::cout << "Value: " << curr.GetValue() << std::endl;
    std::cout << "Is it hard wired? " << curr.GetHardWired() << std::endl;
    std::cout << "*****************************************************" << std::endl;

}

void showRandomCells(Puzzle puzzle){

    for(int i = 0; i < 3; i++){

        srand((unsigned) time(NULL));
        int randomRow = rand() % 9 + 0;
        int randomCol = rand() % 9 + 0;

        printCellData(puzzle, randomRow, randomCol);
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "" << std::endl;

    Puzzle puzzle;

    int rowSize = 9;
    int colSize = 9;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            LoadGame(&puzzle, i, j);
        }
    }

    printPuzzle(puzzle,rowSize,colSize);
    showRandomCells(puzzle);
}