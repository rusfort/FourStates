/*
 * world.h
 *
 *  Created on: 17 нояб. 2021 г.
 *      Author: rusfort
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "bigmap.h"
#include "states.h"
#include <exception>
#include <memory>

class World{
private:
	int WsizeX;
	int WsizeY;
	Map M;
	std::vector<State> _W;
public:
	explicit World(int sizeX, int sizeY);
	void Process();
	inline const Map& getmap() const{
		return M;
	}
	inline Map& getmaptochange(){
		return M;
	}
	inline State& operator()(int snum){
		if (snum < 1 || snum > 4) throw std::out_of_range("State number must be 1, 2, 3 or 4");
		return _W[snum-1];
	}
	void ReloadCell(int rw, int cl);
	void ReloadMap();
	~World();
};


#endif /* WORLD_H_ */
