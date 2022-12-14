#include "Puzzle.hpp"
#include "Cell.hpp"
// #include "History.hpp"
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


//LoopOverPuzzle(&puzzle, &PrintSolution);
//

// void PrintPuzzle(Puzzle* puzzle)
// {
//     std::cout << "\n";
//     std::cout << "||===|===|===||===|===|===||===|===|===||\n";
//     for (int r = 0; r < 9; r++) {
//         for (int c = 0; c < 9; c++) {

//             int v = puzzle->GetCell(r, c)->GetSolution();
//             if ((c == 0) || (c == 3) || (c == 6)) {
//                 std::cout << "||";
//                 if (v != 0) std::cout << ' ' << v << ' ';
//                 else std::cout << "   ";
//             }
//             else {
//                 std::cout << "|";
//                 if (v != 0) std::cout << ' ' << v << ' ';
//                 else std::cout << "   ";
//             }
//             if (c == 8) {
//                 std::cout << "||\n";
//                 if ((r == 2) || (r == 5)) std::cout << "||===|===|===||===|===|===||===|===|===||\n";
//                 else if (r != 8) std::cout << "||---|---|---||---|---|---||---|---|---||\n";
//             }
//         }
//     }
//     std::cout << "||===|===|===||===|===|===||===|===|===||\n";
// }

int main() {
    Puzzle* puzzle = new Puzzle();
    int val = puzzle->GetCell(2,2)->GetValue();
    LoadPuzzle(puzzle, EvilPuzzle);     // Create function to set array to puzzle type (I think this should be the LoadPuzzle function?)
    PrintPuzzle(puzzle);
    cout << endl;
    SolveBruteForce(puzzle);
    PrintPuzzle(puzzle);
    cout << endl;
    CheckPuzzle(puzzle);
 
    return 0;

}