#include "Director.h"

int main() {
	// Simulator( columns, rows, turns, non-predators, predators );
	Director* director = new Director(10, 10, 20, 10, 5);
	director->run();
	return 0;
}