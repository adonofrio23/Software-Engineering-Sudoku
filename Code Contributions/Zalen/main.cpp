#include "Puzzle.hpp"
#include "Cell.hpp"
#include "History.hpp"
#include "Algorithms.hpp"
#include "Algorithms.cpp"
#include "Cell.cpp"
#include "Puzzle.cpp"

#include <iostream>
#include <string>
using namespace std;


int EvilPuzzle[] = {   0,0,4, 5,0,1, 9,0,0,
                       0,2,0, 0,8,0, 0,3,0,
                       6,0,0, 0,0,0, 0,0,5,
                       0,0,8, 7,0,6, 3,0,0,
                       0,5,0, 0,0,0, 0,9,0,
                       0,0,3, 4,0,8, 5,0,0,
                       3,0,0, 0,0,0, 0,0,9,
                       0,8,0, 0,7,0, 0,6,0,
                       0,0,2, 8,0,5, 1,0,0   };

int MediumPuzzle[] = { 0,7,9, 0,4,0, 5,0,0,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,0,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 0,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };

int EasyPuzzle[] = {   0,7,9, 8,4,0, 5,1,3,
                       1,8,0, 3,5,0, 0,0,0,
                       0,0,0, 1,9,0, 0,6,0,
                       4,1,0, 2,0,9, 6,7,5,
                       0,0,0, 7,0,8, 0,3,0,
                       3,2,7, 5,0,4, 8,0,1,
                       0,3,1, 0,0,0, 7,4,6,
                       9,0,0, 0,7,0, 0,0,0,
                       0,0,0, 4,0,0, 1,0,9 };

void LoadPuzzle(Puzzle* puzzle, int values[])
{
    Cell cell;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cell.SetRow(r);
            cell.SetCol(c);
            cell.SetValue(values[r * 9 + c]);
            if (cell.GetValue() != 0) {
                cell.SetHardwired(true);
                cell.SetSolution(cell.GetValue());
            }
            else {
                cell.SetSolution(0);
                cell.SetHardwired(false);
            }
            for (int i = 0; i < 9; i++) {
                cell.GetNotes()[i] = 0;
            }
            puzzle->SetCell(cell);
        }
    }
}



int main() {
    Puzzle* puzzle = new Puzzle();
    LoadPuzzle(puzzle, EasyPuzzle);     
    PrintPuzzle(puzzle);
    cout << endl;
    SolveBruteForce(puzzle);
    PrintPuzzle(puzzle);
    cout << endl;
    CheckPuzzle(puzzle);
 
    return 0;

}