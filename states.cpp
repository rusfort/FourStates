/*
 * states.cpp
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#include "states.h"

// STATE methods =========================================

State::State(const Map& M, int num):
	_numstate(num),
	terr(M, _numstate) {
	RecalcPower();
}


void State::Analysis(){
	//needs a Strategy
}
void State::Process(){
	//needs Strategy, Borders, etc.
}

void State::RecalcPower(){
	_power = 1.0 * terr.area();
}



