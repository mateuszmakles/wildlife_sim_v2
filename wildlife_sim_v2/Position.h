#ifndef POSITION_H
#define POSITION_H

class Position {
	int x;
	int y;
public:
	Position(int xx, int yy) : x{ xx }, y{ yy } {}

	int& X() { return x; }
	int& Y() { return y; }
};

#endif