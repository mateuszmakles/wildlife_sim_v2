#ifndef ANIMAL_H
#define ANIMAL_H

#include <string_view>
#include "Vector2D.h"

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
	Vector2D coords;
	std::string type;
	bool hasBred;
public:
	Animal(const Vector2D& vect);
	Animal(int pId, const Vector2D& vect);

	static int getAnimalCount() { return numbOfAnimals; }
	static void decrementNumbOfAnimals() { --numbOfAnimals; }

	const Vector2D& getPos() const { return coords; }
	void setPos(const Vector2D& vect) { coords = vect; }

	const Sex getGender() const { return gender; }
	const std::string_view getType() const { return type; }
	bool canBreed() { return !hasBred; }

	void setBreed(int breed) { hasBred = breed; }

	virtual void printInfo() const;

	void move(int dir);
};

#endif