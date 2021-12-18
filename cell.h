/*
 * cell.h
 *
 *  Created on: 18 дек. 2021 г.
 *      Author: rusfort
 */

#ifndef CELL_H_
#define CELL_H_

enum class CellStatus{
	CALM,
	NEUTRAL,
	ATTACK,
	DEFEND,
	CAPITAL
};

class Cell{
public:
	int owner_;
	CellStatus status_;
	int row;
	int col;

	Cell(){
		row = 0;
		col = 0;
		owner_ = 0;
		status_ = CellStatus::CALM;
	}
	Cell(int rw, int cl, int ow){
		row = rw;
		col = cl;
		owner_ = ow;
		status_ = CellStatus::CALM;
	}

};




#endif /* CELL_H_ */
