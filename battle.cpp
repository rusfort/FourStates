/*
 * battle.cpp
 *
 *  Created on: 18 дек. 2021 г.
 *      Author: rusfort
 */

#include "battle.h"

bool CanCaptCell(const State& a, const Cell& c){
	auto M = a.getmaplocalcopy();
	auto NB = NBhood(M, c);
	auto attack_pow = a.getpower() * NB_contains(NB, a.getnum());
	auto defend_pow = M.getstatepower(c.owner_) * NB_contains(NB, c.owner_);

	if (attack_pow > defend_pow) return true; // very basic, but ok

	return false;
}

std::pair<bool, Cell> TryBattle(const State& a, const State& d){
	bool res = false;
	Cell c;

	for (auto i : a.getborder()){
		auto L = getnbstate(a.getmaplocalcopy(), i, d.getnum());
		for (auto j : L){
			if (CanCaptCell(a, j)) return std::make_pair(true, j);
		}
	}

	return std::make_pair(res, c);
}

void DoBattle(State& a, State& d, Cell& c){
	a.CellCaptured(c);
	d.CellLost(c);
}

