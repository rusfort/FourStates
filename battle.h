/*
 * battle.h
 *
 *  Created on: 18 дек. 2021 г.
 *      Author: rusfort
 */

#ifndef BATTLE_H_
#define BATTLE_H_

#include "states.h"

//returns true if the attacker state (a) can win the battle over defender's state (d) cell
bool TryBattle(const State& a, const State& d);

#endif /* BATTLE_H_ */
