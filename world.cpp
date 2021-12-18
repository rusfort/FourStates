/*
 * world.cpp
 *
 *  Created on: 17 нояб. 2021 г.
 *      Author: rusfort
 */

#include "world.h"


// WORLD methods =========================================

World::World(int sizeX, int sizeY){
	M = Map(sizeX, sizeY);
	for (int i = 0; i < 4; ++i){
		State s(M, i + 1, sizeX, sizeY);
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
