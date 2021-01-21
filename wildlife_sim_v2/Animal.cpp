#include "Animal.h"
#include <iostream>

int Animal::numbOfAnimals = 0;

Animal::Animal()
	: gender{ Sex::male }, x{ 0 }, y{ 0 }, id{ numbOfAnimals++ }, type{ "Animal" } {
	printInfo();
	std::cout << " spawned\n";
}

Animal::Animal(int pId) // this one is for predators
	: gender{ Sex::male }, x{ 0 }, y{ 0 }, id{ pId }, type{ "Predator" } {
	printInfo();
	std::cout << " spawned\n";
}

void Animal::printInfo() const {
	std::cout << "( " << x << ',' << y << " )\t" << type;
}

void Animal::goRight() {
	++x;
	printInfo();
	std::cout << " went right\n";
}

void Animal::goLeft() {
	--x;
	printInfo();
	std::cout << " went left\n";
}

void Animal::goDown() {
	++y;
	printInfo();
	std::cout << " went down\n";
}

void Animal::goUp() {
	--y;
	printInfo();
	std::cout << " went up\n";
}