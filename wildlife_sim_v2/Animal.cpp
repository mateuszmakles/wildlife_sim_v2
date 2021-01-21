#include "Animal.h"
#include <iostream>

int Animal::numbOfAnimals = 0;

Animal::Animal()
	: gender{ Sex::male }, x{ 0 }, y{ 0 }, id{ numbOfAnimals++ } {
	std::cout << "( " << x << ',' << y << " )\tAnimal spawned\n";
}

Animal::Animal(int pId) // this one is for predators
	: gender{ Sex::male }, x{ 0 }, y{ 0 }, id{ pId } {
	std::cout << "( " << x << ',' << y << " )\tPredator spawned\n";
}