/*
 * world.cpp
 *
 *  Created on: 17 нояб. 2021 г.
 *      Author: rusfort
 */

#include "world.h"


// WORLD methods =========================================

World::World(int sizeX, int sizeY):
WsizeX(2*sizeX), WsizeY(2*sizeY){
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


	//TESTS:
	DoBattle(_W[0], _W[1], _W[1].getcell(2, 7));
	//END TESTS.

	for (int i = 0; i < 4; ++i){
		_W[i].Process();
		M.update_state_power(_W[i].getnum(), _W[i].getpower());
	}
	for (int i = 0; i < 4; ++i){
		_W[i].UpdateMapLocal(M);
	}

	ReloadMap();
}

void World::ReloadCell(int rw, int cl){
	for (int i = 0; i < 4; ++i){
		if (_W[i].getterritory().cellin(rw, cl)){
			M.setcell(rw, cl, _W[i].getcell(rw, cl));
			break;
		}
	}
}

void World::ReloadMap(){
	for (int i = 0; i < WsizeY; ++i){
		for (int j = 0; j < WsizeX; ++j){
			ReloadCell(i, j);
		}
	}
}

World::~World(){
	_W.clear();
}
