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
		std::cout << "_______________________________\n";
		std::cout << "\n\tTURN: " << currentTurn << '\n' << '\n';

		movePhase();

		++currentTurn;
	}
}

void Director::spawnAnimal() {
	animals.push_back(new Animal);
}

void Director::spawnPredator() {
	animals.push_back(new Predator);
}

void Director::movePhase() {
	int direction;

	for (auto& animal : animals) {
		direction = 0;

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