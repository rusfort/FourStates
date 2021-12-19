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

#include "cell.h"

bool operator== (const Cell& lhs, const Cell& rhs);

class Map{
private:
	std::vector<std::vector<Cell>> _M;
public:
	Map(){}
	explicit Map(int sizeX, int sizeY);
	// getters

	inline std::vector<std::vector<Cell>> getMap() const{
			return _M;
	}
	inline Cell getcell(size_t row, size_t col) const{
		return _M.at(row).at(col);
	}
	inline CellStatus getstate(size_t row, size_t col) const{
		return getcell(row, col).status_;
	}
	inline int getowner(size_t row, size_t col) const{
		return getcell(row, col).owner_;
	}
	inline int getsizeX() const{
		return _M.at(0).size();
	}
	inline int getsizeY() const{
		return _M.size();
	}

	// setters

	bool setstate(size_t row, size_t col, CellStatus cs);
	bool setowner(size_t row, size_t col, int owner);
	bool setcell(size_t row, size_t col, Cell c);

	// others

	void DrawLine(std::vector<Cell> line) const; //draws a line of cells
	void DrawHorB(int pos) const;                //draws horisontal borders
	void Draw() const;                           //draws the Map
	inline bool operator= (const Map& m){
		_M = m.getMap();
		return true;
	}

	// destructor

	~Map();
};

std::list<Neighbour> NBhood(const Map& M, const Cell& C); //neighbourhood of the cell

size_t NB_contains(const std::list<Neighbour>& NB, int owner); //returns how many cells of the specific owner the neighbourhood contains

bool NB_sameowner(const std::list<Neighbour>& NB, int owner); //if the whole neighbourhood contains the same owner

#endif /* BIGMAP_H_ */
