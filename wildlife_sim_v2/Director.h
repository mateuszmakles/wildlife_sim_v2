#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Animal.h"
#include "Predator.h"
#include <vector>

class Director {
	int columns;
	int rows;
	int maxTurns;
	std::vector<Animal*> animals;
public:
	Director(int col, int row, int turns, int nons, int preds);

	void run();

private:
	void spawnAnimal();
	void spawnPredator();
};

#endif