/*
 * states.cpp
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#include "states.h"

State::State(const Map& M, int num){
	_numstate = num;
	Territory T(M, _numstate);
	terr = T;
}
