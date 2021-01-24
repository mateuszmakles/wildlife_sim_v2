#ifndef ANIMAL_H
#define ANIMAL_H

#include <string_view>

class Animal {
public:
	enum class Sex : char {
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
	std::string type;
	bool hasBred;
public:
	Animal(int xx, int yy);
	Animal(int pId, int xx, int yy);

	static int getAnimalCount() { return numbOfAnimals; }
	static void decrementNumbOfAnimals() { --numbOfAnimals; }

	const Sex getGender() const { return gender; }
	const int getX() const { return x; }
	const int getY() const { return y; }
	const std::string_view getType() const { return type; }
	bool canBreed() { return !hasBred; }

	void setBreed(int breed) { hasBred = breed; }

	virtual void printInfo() const;

	void move(int dir);
	void goRight();
	void goLeft();
	void goDown();
	void goUp();
};

#endif