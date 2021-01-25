#include "Predator.h"
#include <iostream>

int Predator::numbOfPredators = 0;

Predator::Predator(const Vector2D& vect)
	: Animal{ numbOfPredators++,vect }, hunger{ 0 } {}