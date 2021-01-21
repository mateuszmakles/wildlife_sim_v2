#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Animal.h"
#include <vector>

class Simulator {
	int columns;
	int rows;
	int maxTurns;
	std::vector<Animal*> animals;
public:
	Simulator(int col, int row, int turns, int nons, int preds);

	
};

#endif