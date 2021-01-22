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
	const int getRandom(int max) const;

	void spawnAnimal(int xx, int yy);
	void spawnPredator(int xx, int yy);

	bool compareForBreed(Animal* a1, Animal* a2) const;
	bool compareForEat(Animal* a1, Animal* a2) const;

	void deleteAnimal(Animal* animal);

	void movePhase();
	void resolve();
};

#endif