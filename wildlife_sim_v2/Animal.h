#ifndef ANIMAL_H
#define ANIMAL_H

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
public:
	Animal();
	Animal(int pId);
};

#endif