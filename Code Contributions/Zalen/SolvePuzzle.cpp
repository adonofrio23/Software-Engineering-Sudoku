#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>


using namespace std;

class Puzzle {
    public: 
    int row; 
    int col;

    Puzzle(int r, int c) {
        row = r;
        col = c;
    }

    Puzzle SolvePuzzle(Puzzle currentPuzzle);       
    void PrintPuzzle();


};

Puzzle::Puzzle(int r, int c) {
    row = r;
    col = c;
}

Puzzle Puzzle::SolvePuzzle(Puzzle currentPuzzle) {

}

void Puzzle :: PrintPuzzle() {

    
}


int main() {
    //create sample suduko puzzle
   int puzzle[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
    

    return 0; 
}