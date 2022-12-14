 #include "Algorithms.hpp"
 #include <iostream> 

using namespace std;
// CheckVal checks if the value of the cell is valid
bool CheckVal(Puzzle * puzzle, int row, int col) {
    	int val = puzzle->GetCell(row, col)->GetSolution();
    	
        if (val == 0)
    		return true;
    	
        for (int i = 0; i < 9; i++) {
    		if (i != col && puzzle->GetCell(row, i)->GetSolution() == val)
    			return false;
    		if (i != row && puzzle->GetCell(i, col)->GetSolution() == val)
    			return false;
    	}

    	int rowStart = (row) / 3 * 3;
    	int colStart = (col) / 3 * 3;

    	for (int i = rowStart; i < rowStart + 3; i++) {
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
bool SolveBruteForce(Puzzle* puzzle)
{
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			Cell* cell;
			cell = puzzle->GetCell(row, col);
			if (cell->GetSolution() == 0) {
				for (int val = 1; val < 10; val++) {
					cell->SetSolution(val);
					if (CheckVal(puzzle, row, col)) {
						if ((row == 8) && (col == 8)) { return true; }
						if (SolveBruteForce(puzzle)) { return true; }
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

bool CheckPuzzle(Puzzle* puzzle) {
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
    std::cout << "\n";
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            int v = puzzle->GetCell(r, c)->GetSolution();
            if ((c == 0) || (c == 3) || (c == 6)) {
                std::cout << "||";
                if (v != 0) std::cout << ' ' << v << ' ';
                else std::cout << "   ";
            }
            else {
                std::cout << "|";
                if (v != 0) std::cout << ' ' << v << ' ';
                else std::cout << "   ";
            }
            if (c == 8) {
                std::cout << "||\n";
                if ((r == 2) || (r == 5)) std::cout << "||===|===|===||===|===|===||===|===|===||\n";
                else if (r != 8) std::cout << "||---|---|---||---|---|---||---|---|---||\n";
            }
        }
    }
    std::cout << "||===|===|===||===|===|===||===|===|===||\n";
}



