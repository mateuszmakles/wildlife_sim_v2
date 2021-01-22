#include "Predator.h"
#include <iostream>

int Predator::numbOfPredators = 0;

Predator::Predator(int xx, int yy)
	: Animal{ numbOfPredators++,xx,yy }, hunger{ 0 } {}