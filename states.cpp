/*
 * states.cpp
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#include "states.h"

// STATE methods =========================================

State::State(const Map& M, int num, int x, int y):
	_numstate(num), terr(M, _numstate), SX(x), SY(y){
	RecalcPower();
	SetCap(GetBestCapPlace(), true);
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

Cell& State::getcell(int rw, int cl){
	for (auto& i : terr.getterr()){
		if (i.row == rw && i.col == cl) return i;
	}
	return *(terr.getterr().begin());
}

Cell& State::GetBestCapPlace(){
	//TODO: needs a good algorithm, not setting default capitals
	switch (_numstate){
	case 1:
		return getcell(1, 1);
	case 2:
		return getcell(SX - 2, 1);
	case 3:
		return getcell(1, SY - 2);
	case 4:
		return getcell(SX - 2, SY - 2);
	}
	return getcell(0, 0);
}


