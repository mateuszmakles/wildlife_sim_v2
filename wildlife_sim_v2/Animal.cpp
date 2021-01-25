#include "Animal.h"
#include <iostream>

int Animal::numbOfAnimals = 0;

Animal::Animal(int xx, int yy)
	: gender{ static_cast<Sex>(rand() % 2) }, x{ xx }, y{ yy }, id{ numbOfAnimals++ }, type{ "Animal" }, hasBred{ 0 } {
	printInfo();
	std::cout << " spawned\n";
}

Animal::Animal(int pId, int xx, int yy) // this one is for predators
	: gender{ static_cast<Sex>(rand() % 2) }, x{ xx }, y{ yy }, id{ pId }, type{ "Predator" }, hasBred{ 0 } {
	printInfo();
	std::cout << " spawned\n";
}

void Animal::printInfo() const {
	std::cout << "( " << x << ',' << y << " )\t" << type;
}

void Animal::move(int dir) {
	switch (dir) {
	case 0: // go right
		++x;
		printInfo();
		std::cout << " went right\n";
		break;
	case 1: // go left
		--x;
		printInfo();
		std::cout << " went left\n";
		break;
	case 2: // go down
		++y;
		printInfo();
		std::cout << " went down\n";
		break;
	case 3: // go up
		--y;
		printInfo();
		std::cout << " went up\n";
	}
}