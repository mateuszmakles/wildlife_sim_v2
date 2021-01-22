#include "Director.h"

int main() {
	// Director( columns, rows, turns, non-predators, predators );
	Director* director = new Director(10, 10, 15, 20, 10);
	director->run();
	return 0;
}