/*
 * territory.h
 *
 *  Created on: 17 нояб. 2021 г.
 *      Author: rusfort
 */

#ifndef TERRITORY_H_
#define TERRITORY_H_

#include <list>
#include "bigmap.h"

class Territory{
private:
	std::list<Cell> T;
public:
	Territory(){}
	explicit Territory(const Map& M, int owner){
		//filling the list
	}
	~Territory(){}
};



#endif /* TERRITORY_H_ */
