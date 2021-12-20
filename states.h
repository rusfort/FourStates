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
	Cell* cell;
};

class State{
private:
	const int _numstate;
	Capital cap;
	double _power = 0.0;
	//Strategy strat; //TODO
	Territory terr;
	int SX; //size X of the rectangle, which contains the whole territoty
	int SY; //size Y of the rectangle, which contains the whole territoty
	std::list<Cell> Border;
	Map WORLDMAP; //local copy of world map
public:
	explicit State(const Map& M, int num, int x, int y);

	// service functions

	void RecalcPower();
	void UpdateMapLocal(const Map& M);
	void UpdateBorder();
	void Analysis();   // getting world data about the current situation
	void Process();    // after analysing the situation the state makes a decision
	Cell& GetBestCapPlace(); // finds the best cell for capital
	inline bool iscap(const Cell& c) const{ // retuns whether a cell is a capital of state
		return *(cap.cell) == c;
	}

	// getters

	inline int getnum() const{
		return _numstate;
	}
	inline double getpower() const{
		return _power;
	}
	inline Territory getterritory() const{
		return terr;
	}
	inline Capital getcapital() const{
		return cap;
	}
	inline Map getmaplocalcopy() const{
		return WORLDMAP;
	}
	inline std::list<Cell> getborder() const{
		return Border;
	}
	Cell& getcell(int rw, int cl);
	inline size_t borderlen() const{
		return Border.size();
	}

	// setters

	inline void SetCap(Cell& c, bool init = false){ //sets a capital
		if (!init) cap.cell->status_ = CellStatus::NEUTRAL;
		cap.cell = &c;
		cap.cell->status_ = CellStatus::CAPITAL;
	}
	void CellCaptured (Cell& c);
	void CellLost (const Cell& c);

	// destructor

	~State(){}
};

#endif /* STATES_H_ */
