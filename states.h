/*
 * states.h
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#ifndef STATES_H_
#define STATES_H_

#include <vector>
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

	// service functions

	void RecalcPower();
	void Analysis();   // getting world data about the current situation
	void Process();    // after analysing the situation the state makes a decision

	// getters

	inline int getnum() const{
		return _numstate;
	}
	inline int getpower() const{
		return _power;
	}
	inline Territory getterritory() const{
		return terr;
	}
	inline Capital getcapital() const{
		return cap;
	}

	// setters

	//TODO

	// destructor

	~State(){}
};

class World{
private:
	std::vector<State> _W;
public:
	explicit World(const Map& M);
	void Process();
	~World();
};

#endif /* STATES_H_ */
