/*
* temp for coloring states
*/
#pragma once

#include <random>


class StateColor {
public:
	int stateId = 0;
	int r, g, b;
};

class StateColorManagerTemp {
private:
	std::vector<StateColor> stateColors;
	const int range_from = 0;
	const int range_to = 255;
	std::random_device rand_dev;
	std::mt19937 generator;
	std::uniform_int_distribution <int> distr;
public:
	StateColorManagerTemp();

	StateColor getStateByID(int id);
};