#include "Director.h"
#include <iostream>

Director::Director(int col, int row, int turns, int nons, int preds)
	: columns{ col }, rows{ row }, maxTurns{ turns } {
	for (int i = 0; i < nons; ++i) {
		spawnAnimal();
	}
	for (int i = 0; i < preds; ++i) {
		spawnPredator();
	}
}

void Director::run() {
	int currentTurn = 1;

	while (currentTurn <= maxTurns) {
		std::cout << "\n\tTURN: " << currentTurn << '\n' << '\n';

		++currentTurn;
	}
}

void Director::spawnAnimal() {
	animals.push_back(new Animal);
}

void Director::spawnPredator() {
	animals.push_back(new Predator);
}