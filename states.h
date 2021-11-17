/*
 * states.h
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#ifndef STATES_H_
#define STATES_H_

#include "bigmap.h"
#include "territory.h"

struct Capital{
	Cell cell;
};

class State{
private:
	int _numstate;
	Capital cap;
	double _power = 0.0;
	//Strategy strat; //TODO
	Territory terr;
public:
	explicit State(const Map& M, int num);
	void RecalcPower();
	void Process();
	inline int getnum() const{
		return _numstate;
	}
	inline int getpower() const{
		return _power;
	}
	inline Territory getterritory() const{
		return terr;
	}
	~State(){}
};

#endif /* STATES_H_ */
