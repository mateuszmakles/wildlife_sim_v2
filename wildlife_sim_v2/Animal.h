#ifndef ANIMAL_H
#define ANIMAL_H

#include <string_view>

class Animal {
public:
	enum class Sex {
		male,
		female,

		MAX
	};
private:
	static int numbOfAnimals;
	int id;
	Sex gender;
	int x;
	int y;
	std::string_view type;
public:
	Animal();
	Animal(int pId);

	const int getX() const { return x; }
	const int getY() const { return y; }

	virtual void printInfo() const;

	void goRight();
	void goLeft();
	void goDown();
	void goUp();
};

#endif