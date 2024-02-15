#include <utils/stateColor.h>

StateColorManagerTemp::StateColorManagerTemp() {
	generator = std::mt19937(rand_dev());
	distr = std::uniform_int_distribution <int>(range_from, range_to);
}

StateColor StateColorManagerTemp::getStateByID(int id) {
    int guess = stateColors.size() / 2, max = stateColors.size(), min = 0;
    while(max > min){
        guess = (int) ((max + min) / 2);
        if(stateColors[guess].stateId == id){
            return stateColors[guess];
        }else if(stateColors[guess].stateId < id){
            // less than
            min = guess + 1;
        }else{
            // more lamo
            max = guess;
        }
    }
	StateColor tmp;
	tmp.stateId = id;
	tmp.r = distr(generator);
	tmp.g = distr(generator);
	tmp.b = distr(generator);
	stateColors.push_back(tmp);
    sort();
	return tmp;
}

void StateColorManagerTemp::sort(){
    bool bad = false;
    for(int i = 0; i < stateColors.size() - 1; i++){
        if(stateColors[i].stateId > stateColors[i+1].stateId){
            bad = true;
            StateColor tmp = stateColors[i];
            stateColors[i] = stateColors[i + 1];
            stateColors[i+1] = tmp;
        }
    }
    if(bad) sort();
}

