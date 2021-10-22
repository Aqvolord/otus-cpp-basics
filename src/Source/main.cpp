#include "src/Include/Min.h"
#include "src/Include/Max.h"
#include "src/Include/Std.h"

#include <iostream>



int main() {

	const size_t statistics_count = 4;
	IStatistics* statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	std::cout << "Enter a sequence of numbers: " << std::endl;
	float value;
	while (std::cin >> value) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->change(value);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->getName() << " = " << statistics[i]->getMeaning() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}