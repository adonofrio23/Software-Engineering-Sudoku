 #include "Algorithms.hpp"
 #include <iostream> 

using namespace std;

// CheckVal loops through and checks every value in the row, column, to see if it is valid
bool CheckVal(Puzzle * puzzle, int row, int col) {
    	int val = puzzle->GetCell(row, col)->GetSolution();
    	
        if (val == 0)
    		return true;
    	
        for (int i = 0; i < 9; i++) {
    		if (i != col && puzzle->GetCell(row, i)->GetSolution() == val)   // Check the row
    			return false;
    		if (i != row && puzzle->GetCell(i, col)->GetSolution() == val)   // Check the column
    			return false;
    	}

    	int rowStart = (row) / 3 * 3;      // Get the starting row and column of the 3x3 square
    	int colStart = (col) / 3 * 3;       

    	for (int i = rowStart; i < rowStart + 3; i++) {          // Check the 3x3 square
    		for (int j = colStart; j < colStart + 3; j++) {
    		  if ((i != row) || (j != col)) {
				if (puzzle->GetCell(i, j)->GetSolution() == val) 
				    return false;
			}
    	  }
    	}
    	return true;
    }

// Reference https://www.tutorialspoint.com/sudoku-solver-in-cplusplus 
bool SolveBruteForce(Puzzle* puzzle) {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			Cell* cell;
			cell = puzzle->GetCell(row, col); 
			if (cell->GetSolution() == 0) {
				for (int val = 1; val < 10; val++) {
					cell->SetSolution(val);
					if (CheckVal(puzzle, row, col)) {
						if ((row == 8) && (col == 8)) { return true; } //I f we are at the end of the puzzle, return true
						if (SolveBruteForce(puzzle)) { return true; } // Solve recursively
					}
				}
				cell->SetSolution(0);
				return false;
			}
		}
	}
	return true;  
}

// CheckPuzzle checks if the puzzle is correct
// Reference https://www.geeksforgeeks.org/check-if-given-sudoku-board-configuration-is-valid-or-not/

bool CheckPuzzle(Puzzle* puzzle) {          // Check if the puzzle is correct against solution
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			Cell* cell;
			cell = puzzle->GetCell(row, col);
			if ((cell->GetSolution() != cell->GetValue()) && (cell->GetValue() != 0)) {
				return false;
			}
		}
	}
	return true;
}

void PrintPuzzle(Puzzle* puzzle)
{
    cout << "\n";
    cout << "||===|===|===||===|===|===||===|===|===||\n";
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            int v = puzzle->GetCell(r, c)->GetSolution();
            if ((c == 0) || (c == 3) || (c == 6)) {
                cout << "||";
                if (v != 0) cout << ' ' << v << ' ';
                else cout << "   ";
            }
            else {
                cout << "|";
                if (v != 0) cout << ' ' << v << ' ';
                else cout << "   ";
            }
            if (c == 8) {
                cout << "||\n";
                if ((r == 2) || (r == 5)) cout << "||===|===|===||===|===|===||===|===|===||\n";
                else if (r != 8) cout << "||---|---|---||---|---|---||---|---|---||\n";
            }
        }
    }
    cout << "||===|===|===||===|===|===||===|===|===||\n";
}



