/*
 * territory.cpp
 *
 *  Created on: 17 дек. 2021 г.
 *      Author: rusfort
 */

#include "territory.h"

Territory::Territory(const Map& M, int owner){
	for (int i = 0; i < M.getsizeX(); ++i){
		for (int j = 0; j < M.getsizeY(); ++j){
			auto c = M.getcell(i, j);
			if (c.owner_ == owner) T.push_back(c);
		}
	}
}

bool Territory::cellin(int rw, int cl){
	for (auto i : T){
		if (i.row == rw && i.col == cl) return true;
	}
	return false;
}

