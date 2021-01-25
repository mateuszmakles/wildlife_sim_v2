#include "Animal.h"
#include <iostream>

int Animal::numbOfAnimals = 0;

Animal::Animal(const Vector2D& vect)
	: gender{ static_cast<Sex>(rand() % 2) }, coords{ vect }, id{ numbOfAnimals++ }, type{ "Animal" }, hasBred{ 0 } {
	printInfo();
	std::cout << " spawned\n";
}

Animal::Animal(int pId, const Vector2D& vect) // this one is for predators
	: gender{ static_cast<Sex>(rand() % 2) }, coords{ vect }, id{ pId }, type{ "Predator" }, hasBred{ 0 } {
	printInfo();
	std::cout << " spawned\n";
}

void Animal::printInfo() const {
	std::cout << "( " << coords.x << ',' << coords.y << " )\t" << type;
}

void Animal::move(int dir) {
	switch (dir) {
	case 0: // go right
		++coords.x;
		printInfo();
		std::cout << " went right\n";
		break;
	case 1: // go left
		--coords.x;
		printInfo();
		std::cout << " went left\n";
		break;
	case 2: // go down
		++coords.y;
		printInfo();
		std::cout << " went down\n";
		break;
	case 3: // go up
		--coords.y;
		printInfo();
		std::cout << " went up\n";
	}
}