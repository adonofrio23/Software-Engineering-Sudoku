#ifndef SOFTWARE_ENGINEERING_SUDOKU_ALGORITHMS_H
#define SOFTWARE_ENGINEERING_SUDOKU_ALGORITHMS_H

#pragma once
#include "../Dylon/Puzzle.h"
#include <vector>


class Algorithms {
    private:

    public:
    int RankDifficulty (Puzzle* puzzle);
    bool CheckVal(Puzzle * puzzle, int row, int col);
    bool SolveBruteForce(Puzzle* puzzle);
    bool CheckPuzzle(Puzzle* puzzle);
    void PopulatePossibilities(Puzzle* puzzle);
    bool UseSingletons(Puzzle* puzzle);
    bool UseOnlyChoice(Puzzle* puzzle);
    bool PuzzleComplete(Puzzle* puzzle);
    void PrintPuzzle(Puzzle* puzzle);
    std::vector<Cell> FindAllErrors(Puzzle* puzzle);
	std::vector<Cell> FindAllEmpty(Puzzle* puzzle);

};


#endif
