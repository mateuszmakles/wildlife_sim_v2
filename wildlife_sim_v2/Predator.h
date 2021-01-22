#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal {
	static int numbOfPredators;
public:
	Predator(int xx, int yy);

	static int getPredatorCount() { return numbOfPredators; }

	static void decrementNumbOfPredators() { --numbOfPredators; }
};

#endif