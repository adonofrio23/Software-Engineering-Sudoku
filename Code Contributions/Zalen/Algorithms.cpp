 #include "Algorithms.hpp"
 #include <iostream> 

using namespace std;
// CheckVal checks if the value of the cell is valid
bool CheckVal(Puzzle * puzzle, int row, int col) {
    	int val = puzzle->GetCell(row, col)->GetValue();
    	
        if (val == 0)
    		return true;
    	
        for (int i = 0; i < 9; i++) {
    		if (i != col && puzzle->GetCell(row, i)->GetValue() == val)
    			return false;
    		if (i != row && puzzle->GetCell(i, col)->GetValue() == val)
    			return false;
    	}

    	int rowStart = (row / 3) * 3;
    	int colStart = (col / 3) * 3;

    	for (int i = rowStart; i < rowStart + 3; i++) {
    		for (int j = colStart; j < colStart + 3; j++) {
    			if (i != row && j != col && puzzle->GetCell(i, j)->GetValue() == val) {
    				return false;
                }
    		}
    	}
    	return true;
    }

// Reference https://www.tutorialspoint.com/sudoku-solver-in-cplusplus
void SolveBruteForce(Puzzle* puzzle) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (puzzle->GetCell(i, j)->GetValue() == 0) {
					for (int k = 1; k <= 9; k++) {
						puzzle->GetCell(i, j)->SetValue(k);
						if (CheckVal(puzzle, i, j) && CheckPuzzle(puzzle)) {
							SolveBruteForce(puzzle);
						}
						puzzle->GetCell(i, j)->SetValue(0);
					}
				}
			}
		}
		PrintPuzzle(puzzle);
	}

// CheckPuzzle checks if the puzzle is correct
// Reference https://www.geeksforgeeks.org/check-if-given-sudoku-board-configuration-is-valid-or-not/

bool CheckPuzzle(Puzzle* puzzle) {
    for (int i = 0; i < 9; i++) {
    	for (int j = 0; j < 9; j++) {
    		if (!CheckVal(puzzle, i, j))
    			return false;
    	}
    }
    return true;
}



