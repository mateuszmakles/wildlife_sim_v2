#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2D {
	int x;
	int y;

	Vector2D(int xx, int yy) : x{ xx }, y{ yy } {}
};

#endif