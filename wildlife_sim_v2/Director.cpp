#include "Director.h"
#include "Animal.h"
#include "Predator.h"
#include <iostream>
#include <random>
#include <ctime>

Director::Director(int col, int row, int turns, int nons, int preds)
	: columns{ col }, rows{ row }, maxTurns{ turns } {
	for (int i = 0; i < nons; ++i) {
		spawnAnimal(getRandom(columns - 1), getRandom(rows - 1));
	}
	for (int i = 0; i < preds; ++i) {
		spawnPredator(getRandom(columns - 1), getRandom(rows - 1));
	}
}

void Director::run() {
	int currentTurn = 1;

	while (currentTurn <= maxTurns && Animal::getAnimalCount() > 0 && Predator::getPredatorCount() > 0) {
		std::cout << "_______________________________\n";
		std::cout << "\n\tTURN: " << currentTurn << '\n' << '\n';

		movePhase();

		resolve();

		hungerPhase();

		++currentTurn;
	}

	if (!animals.empty()) {
		for (auto& element : animals) {
			delete element;
		}
		animals.clear();
	}
}

const int Director::getRandom(int max) const {
	static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution roll{ 0, max };
	return roll(mersenne);
}

void Director::spawnAnimal(int xx, int yy) {
	animals.push_back(new Animal(xx, yy));
}

void Director::spawnPredator(int xx, int yy) {
	animals.push_back(new Predator(xx, yy));
}

bool Director::compareForBreed(Animal* a1, Animal* a2) const {
	return (a1->getGender() != a2->getGender() && a1->getType() == a2->getType() && a1->canBreed() && a2->canBreed());
}

bool Director::compareForEat(Animal* a1, Animal* a2) const {
	return (a1->getType() == "Predator" && a2->getType() == "Animal");
}

void Director::deleteAnimal(Animal* animal) {
	if (!animals.empty()) {
		animal->getType() == "Animal" ? Animal::decrementNumbOfAnimals() : Predator::decrementNumbOfPredators();
		auto it = std::find(animals.begin(), animals.end(), animal);
		delete animal;
		animals.erase(it);
	}
}

void Director::movePhase() {
	int direction;

	for (auto& animal : animals) {
		direction = getRandom(3);
		//animal->move(getRandom(3)); i getPosition();

		switch (direction) {
		case 0: // go right
			if (animal->getX() < columns - 1) {
				animal->goRight();
			}
			break;
		case 1: // go left
			if (animal->getX() > 0) {
				animal->goLeft();
			}
			break;
		case 2: // go down
			if (animal->getY() < rows - 1) {
				animal->goDown();
			}
			break;
		case 3: // go up
			if (animal->getY() > 0) {
				animal->goUp();
			}
		}
	}
}

void Director::hungerPhase() {
	for (auto& p : animals) {

		if (p->getType() == "Predator") {

			Predator* pred{ dynamic_cast<Predator*>(p) };

			if (pred) {
				pred->hasEaten() ? pred->resetHunger() : pred->starve();

				if (pred->isDead()) {
					p->printInfo();
					std::cout << " has died of starvation\n";
					deleteAnimal(p);
				}
			}
		}
	}
}

void Director::resolve() {
	auto a = animals; // we're going to loop through this copy to not interrupt original through adding and deleting animals

	for (int i = 0; i < a.size(); ++i) {

		for (int ii = 0; ii < a.size(); ++ii) {

			if (a[i] != a[ii] && a[i]->getX() == a[ii]->getX() && a[i]->getY() == a[ii]->getY()) {

				// Breeding with second animal
				if (compareForBreed(a[i], a[ii])) {
					a[i]->setBreed(1);
					a[ii]->setBreed(1);

					a[i]->printInfo();
					std::cout << "s have bred\n";

					if (a[i]->getType() == "Animal") {
						spawnAnimal(a[i]->getX(), a[i]->getY());
					}
					else {
						spawnPredator(a[i]->getX(), a[i]->getY());
					}
				}

				// Eating second animal
				if (compareForEat(a[i], a[ii])) {
					deleteAnimal(a[ii]);
					Predator* pred{ dynamic_cast<Predator*>(a[i]) };
					if (pred) {
						pred->eat();
					}
					a[i]->printInfo();
					std::cout << " has eaten an animal\n";
				}

			}
		}
	}
}