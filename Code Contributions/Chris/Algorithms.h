#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "../Dylon/Puzzle.h"
#include "../Anthony/Cell.h"
#include <vector>

class Algorithms {

public:
	std::vector<Cell> FindAllErrors(Puzzle* puzzle);
	std::vector<Cell> FindAllEmpty(Puzzle* puzzle);

};

#endif