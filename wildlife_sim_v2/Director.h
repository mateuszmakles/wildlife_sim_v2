#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <vector>

struct Vector2D;

class Animal;

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

	void spawnAnimal(const Vector2D& vect);
	void spawnPredator(const Vector2D& vect);

	bool compareForBreed(Animal* a1, Animal* a2) const;
	bool compareForEat(Animal* a1, Animal* a2) const;

	void deleteAnimal(Animal* animal);

	void movePhase();
	void resolve();
	void hungerPhase();
};

#endif