#include "Predator.h"
#include <iostream>

int Predator::numbOfPredators = 0;

Predator::Predator()
	: Animal{ numbOfPredators++ } {}