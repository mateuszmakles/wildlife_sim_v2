#include <random> // for std::mt19937
#include <ctime> // for std::time

int getRandomNumber(int min, int max) {
	// Mersenne Twister for maximum randomness
	static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution roll{ min, max };
	return roll(mersenne);
}