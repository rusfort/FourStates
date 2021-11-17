/*
 * bigmap.h
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#ifndef BIGMAP_H_
#define BIGMAP_H_

#include <vector>
#include <string>
#include <map>
#include <iostream>

enum class CellStatus{
	CALM,
	NEUTRAL,
	ATTACK,
	DEFEND
};

struct Cell{
	int owner_;
	CellStatus status_;
	int row;
	int col;
};

class Map{
private:
	std::vector<std::vector<Cell>> _M;
public:
	Map(){}
	explicit Map(int sizeX, int sizeY);
	// getters

	inline Cell getcell(size_t row, size_t col) const{
		return _M.at(col).at(row);
	}
	inline CellStatus getstate(size_t row, size_t col) const{
		return getcell(row, col).status_;
	}
	inline int getowner(size_t row, size_t col) const{
		return getcell(row, col).owner_;
	}

	// setters

	bool setstate(size_t row, size_t col, CellStatus cs);
	bool setowner(size_t row, size_t col, int owner);
	bool setcell(size_t row, size_t col, Cell c);

	// others

	void DrawLine(std::vector<Cell> line) const; //draws a line of cells
	void DrawHorB(int pos) const;                //draws horisontal borders
	void Draw() const;                           //draws the Map

	// destructor

	~Map();
};

#endif /* BIGMAP_H_ */
