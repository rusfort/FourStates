/*
 * battle.h
 *
 *  Created on: 18 дек. 2021 г.
 *      Author: rusfort
 */

#ifndef BATTLE_H_
#define BATTLE_H_

#include "states.h"
#include <map>

//returns true if the attacker state (a) can win the battle over defender's state (d) cell
std::pair<bool, Cell> TryBattle(const State& a, const State& d);

//process of capturing cell 'c' from state 'd' by state 'a'
void DoBattle(State& a, State& d, Cell& c);

#endif /* BATTLE_H_ */
