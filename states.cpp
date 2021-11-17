/*
 * states.cpp
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#include "states.h"

// STATE methods =========================================

State::State(const Map& M, int num){
	_numstate = num;
	Territory T(M, _numstate);
	terr = T;
}

void State::Analysis(){
	//needs a Strategy
}
void State::Process(){
	//needs Strategy, Borders, etc.
}


// WORLD methods =========================================

World::World(const Map& M){
	for (int i = 0; i < 4; ++i){
		State s(M, i + 1);
		_W.push_back(s);
	}
}

void World::Process(){
	for (int i = 0; i < 4; ++i){
		_W[i].Analysis();
	}
	for (int i = 0; i < 4; ++i){
		_W[i].Process();
	}
}

World::~World(){
	_W.clear();
}
