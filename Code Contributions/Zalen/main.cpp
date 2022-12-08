#include "Puzzle.hpp"
#include "Cell.hpp"
#include "History.hpp"
#include "Algorithms.hpp"

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

int main() {
    Puzzle* puzzle = new Puzzle();
    puzzle->loadPuzzle(puzzle, EvilPuzzle);     // Create function to set array to puzzle type (I think this should be the LoadPuzzle function?)
    PrintPuzzle(puzzle);
    cout << endl;
    SolveBruteForce(puzzle);
    PrintPuzzle(puzzle);
    cout << endl;
    CheckPuzzle(puzzle);
 
    return 0;

}