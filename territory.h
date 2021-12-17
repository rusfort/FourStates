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
	explicit Territory(const Map& M, int owner);

	// getters

	inline bool is_empty(){
		return T.empty();
	}
	inline int area(){
		return T.size();
	}
	double whole_border_length(); //returns a length of border (MAY HAVE TO BE RELOCATED)

	// setters

	//

	// destructor

	~Territory(){}
};



#endif /* TERRITORY_H_ */
