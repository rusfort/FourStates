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

class World{
private:
	Map M;
	std::vector<State> _W;
public:
	explicit World(int sizeX, int sizeY);
	void Process();
	inline Map getmap() const{
		return M;
	}
	inline Map& getmaptochange(){
		return M;
	}
	~World();
};


#endif /* WORLD_H_ */
