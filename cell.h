/*
 * cell.h
 *
 *  Created on: 18 дек. 2021 г.
 *      Author: rusfort
 */

#ifndef CELL_H_
#define CELL_H_

#include <list>

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

enum class NeighbourType{
	ORT, //horisontal or vertical
	DIAG //diagonal
};

class Neighbour : public Cell{
public:
	NeighbourType type;

	Neighbour(int rw, int cl, int ow, CellStatus st, NeighbourType tp):
		Cell(rw, cl, ow), type(tp) {
		status_ = st;
	}
};

Neighbour ConvCellToNB (const Cell& C, NeighbourType t);

Cell ConvNBToCell (const Neighbour& N);


#endif /* CELL_H_ */
