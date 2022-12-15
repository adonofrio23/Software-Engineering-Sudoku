#include "Algorithms.h"
#include <iostream>
using namespace std;

/// <summary>
/// Puts into notes array of each cell in the puzzle, all possible values that don't
/// conflict along/in its row, column, and group
/// </summary>
/// <param name="puzzle"></param>
void Algorithms:: PopulatePossibilities(Puzzle* puzzle) {
    // zero out all previous notes
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            for (int i = 1; i < 10; i++) {
                puzzle->GetCell(row, col)->SetNotes(i-1, 0);
            }
        }
    }
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (puzzle->GetCell(row, col)->GetSolution() == 0) {
                for (int i = 1; i < 10; i++) {
                    puzzle->GetCell(row, col)->SetSolution(i);
                    if (CheckVal(puzzle, row, col)) {
                        puzzle->GetCell(row,col)->SetNotes(i-1, i);
                    }
                }
                puzzle->GetCell(row, col)->SetSolution(0);
            }
        }
    }
}

/// <summary>
/// Traverses over whole puzzle and looks in each cell's notes for any case where there
/// is only one choice. If yes, it sets the solution with that value
/// </summary>
/// <param name="puzzle"></param>
/// <returns></returns>
bool Algorithms:: UseSingletons(Puzzle* puzzle) {
    bool modified = false;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int numberOfNotes = 0;
            int noteIndex;
            for (int i = 0; i < 9; i++) {
                if (puzzle->GetCell(row, col)->GetNotes()[i] != 0) {
                    numberOfNotes++;
                    noteIndex = i;
                }
            }
            if (numberOfNotes == 1) {
                puzzle->GetCell(row, col)->SetSolution(noteIndex + 1);
                modified = true;
            }
        }
    }
    return modified;
}

/// <summary>
/// Traverses over the puzzle three different ways: by row, by column, and by group
/// looking for where a value occurs only once. When it does, it gets set in the puzzle's
/// solution.
/// </summary>
/// <param name="puzzle"></param>
/// <returns></returns>
bool Algorithms::UseOnlyChoice(Puzzle* puzzle) {
    int tempRow, tempCol;
    bool modified = false;
    // Check across each row for single occurances of each value
    for (int row = 0; row < 9; row++) {
        for (int val = 1; val < 10; val++) {
            bool found = false;
            for (int col = 0; col < 9; col++)
            {
                if (puzzle->GetCell(row, col)->GetNotes()[val - 1] == val) {
                    if (found) {
                        found = false;
                        break;
                    }
                    found = true;
                    tempRow = row;
                    tempCol = col;
                }
            }
            if (found) {
                puzzle->GetCell(tempRow, tempCol)->SetSolution(val);
                modified = true;
            }
        }
    }
    // Check down each column for single occurances of each value
    for (int col = 0; col < 9; col++) {
        for (int val = 1; val < 10; val++) {
            bool found = false;
            for (int row = 0; row < 9; row++)
            {
                if (puzzle->GetCell(row, col)->GetNotes()[val - 1] == val) {
                    if (found) {
                        found = false;
                        break;
                    }
                    found = true;
                    tempRow = row;
                    tempCol = col;
                }
            }
            if (found) {
                puzzle->GetCell(tempRow, tempCol)->SetSolution(val);
                modified = true;
            }
        }
    }
    // Check each group for single occurances of each value
    for (int groupRow = 0; groupRow < 3; groupRow++) {
        for (int groupCol = 0; groupCol < 3; groupCol++) {
            for (int val = 1; val < 10; val++) {
                int found = 0;
                for (int row = groupRow * 3; row < (groupRow * 3 + 3); row++) {
                    for (int col = groupCol * 3; col < (groupCol * 3 + 3); col++) {
                        if (puzzle->GetCell(row, col)->GetNotes()[val - 1] == val) {
                            found++;
                            tempRow = row;
                            tempCol = col;
                        }
                    }
                }
                if (found == 1) {
                    puzzle->GetCell(tempRow, tempCol)->SetSolution(val);
                    modified = true;
                }
            }
        }
    }
    return modified;
}

/*
void Cell::SetNotes()
{
    for(int i = 0; i < 16; i++)
        notes[i] = 0;
}
*/

bool Algorithms::PuzzleComplete(Puzzle *puzzle) {
    for (int r=0; r < 9; r++) {
        for (int c = 0; c<9; c++) {
            if (puzzle->GetCell(r, c)->GetSolution() == 0 ) return false;
        }
    }
    return true;
}



int Algorithms:: RankDifficulty (Puzzle* puzzle) {
    int rank = 3;
    bool mod = true;
    while (mod) {
        PopulatePossibilities(puzzle);
        mod = UseSingletons(puzzle);
    }
    if (PuzzleComplete(puzzle)==true) {
        rank=1;
    } else {
        mod = true;
        while (mod) {
            PopulatePossibilities(puzzle);
            UseSingletons(puzzle);
            mod = UseOnlyChoice(puzzle);
        }
        if (PuzzleComplete(puzzle)==true) {
            rank = 2;
        }
    }
    cout<<"Rank = "<< rank << endl;
    return rank;
}

