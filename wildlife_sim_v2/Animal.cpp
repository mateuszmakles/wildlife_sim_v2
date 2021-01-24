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