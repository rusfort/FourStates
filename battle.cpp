/*
 * battle.cpp
 *
 *  Created on: 18 дек. 2021 г.
 *      Author: rusfort
 */

#include "battle.h"

std::pair<bool, Cell> TryBattle(const State& a, const State& d){
	bool res = false;
	Cell c;

	//TODO

	return std::make_pair(res, c);
}

void DoBattle(State& a, State& d, Cell& c){
	a.CellCaptured(c);
	d.CellLost(c);
}

