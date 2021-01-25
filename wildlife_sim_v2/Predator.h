#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal {
	static int numbOfPredators;
	int hunger;
public:
	Predator(const Vector2D& vect);

	static int getPredatorCount() { return numbOfPredators; }

	static void decrementNumbOfPredators() { --numbOfPredators; }

	void starve() { ++hunger; }
	void resetHunger() { hunger = 0; }
	bool isDead() const { return hunger >= 2; }
	void eat() { hunger = -1; }
	bool hasEaten() const { return hunger == -1; }
};

#endif