/*
 * states.h
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#ifndef STATES_H_
#define STATES_H_

#include "bigmap.h"

struct Capital{
	int state;
	CellStatus status;
};

class State{
private:
	int numstate;
	Capital cap;
	double power;
	//Strategy strat; //TODO
	//Territory terr; //TODO
public:
	//TODO
};

#endif /* STATES_H_ */
