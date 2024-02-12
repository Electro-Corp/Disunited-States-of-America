#include <utils/stateColor.h>

StateColorManagerTemp::StateColorManagerTemp() {
	generator = std::mt19937(rand_dev());
	distr = std::uniform_int_distribution <int>(range_from, range_to);
}

StateColor StateColorManagerTemp::getStateByID(int id) {
	for (auto& state : stateColors) {
		if (state.stateId == id) {
			return state;
		}
	}
	StateColor tmp;
	tmp.stateId = id;
	tmp.r = distr(generator);
	tmp.g = distr(generator);
	tmp.b = distr(generator);
	stateColors.push_back(tmp);
	return tmp;
}