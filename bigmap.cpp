/*
 * bigmap.cpp
 *
 *  Created on: 15 нояб. 2021 г.
 *      Author: rusfort
 */

#include "bigmap.h"

bool operator== (const Cell& lhs, const Cell& rhs){
	return (lhs.col == rhs.col && lhs.row == rhs.row);
}

Map::Map(int sizeX, int sizeY){
	if (sizeX > 1 && sizeY > 1){
		//std::cout << "Initializing Map..." << std::endl;
		Cell c1(0, 0, 1);
		Cell c2(0, 0, 2);
		Cell c3(0, 0, 3);
		Cell c4(0, 0, 4);
		std::vector<Cell> line1;
		std::vector<Cell> line2;
		for (int i = 0; i < sizeX * 2; ++i){
			if (i < sizeX){
				line1.push_back(c1);
				line2.push_back(c3);
			} else {
				line1.push_back(c2);
				line2.push_back(c4);
			}
		}
		for (int i = 0; i < sizeY; ++i) _M.push_back(line1);
		for (int i = 0; i < sizeY; ++i) _M.push_back(line2);
		for (int i = 0; i < sizeX * 2; ++i)
			for (int j = 0; j < sizeY * 2; ++j){
				_M[j][i].col = i;
				_M[j][i].row = j;
			}
	} else {
		std::cout << "Error in generating map: size out of range" << std::endl;
	}
}

Map::~Map(){
	//int sizeY = _M.size();
	_M.clear();
	//if (sizeY > 0) std::cout << "Map destroyed" << std::endl;
}

bool Map::setstate(size_t row, size_t col, CellStatus cs){
	if (col >= _M[0].size()){
		std::cout << "Error in setstate: column out of range" << std::endl;
		return false;
	}
	if (row >= _M.size()){
		std::cout << "Error in setstate: row out of range" << std::endl;
		return false;
	}
	_M[row][col].status_ = cs;
	return true;
}

bool Map::setowner(size_t row, size_t col, int owner){
	if (col >= _M[0].size()){
		std::cout << "Error in setowner: column out of range" << std::endl;
		return false;
	}
	if (row >= _M.size()){
		std::cout << "Error in setowner: row out of range" << std::endl;
		return false;
	}
	_M[row][col].owner_ = owner;
	return true;
}

bool Map::setcell(size_t row, size_t col, Cell c){
	bool cset = true;
	cset = cset & setowner(row, col, c.owner_);
	cset = cset & setstate(row, col, c.status_);
	return cset;
}

void Map::DrawLine(std::vector<Cell> line) const{
	for(auto i : line){
		if (i.status_ != CellStatus::CAPITAL) std::cout << "│ " << i.owner_ << " ";
		else std::cout << "│ ★ ";
	}
	std::cout << "│" << std::endl;
}

void Map::DrawHorB(int pos) const{
	size_t s = _M.at(0).size();
	if (pos == 1)
	{
		std::cout << "┌";
		for(size_t i = 0; i < s; ++i){
			std::cout << "───";
			if (i < s-1) std::cout << "┬";
		}
		std::cout << "┐";
	}
	if (pos == 2)
	{
		std::cout << "└";
		for(size_t i = 0; i < s; ++i){
			std::cout << "───";
			if (i < s-1) std::cout << "┴";
		}
		std::cout << "┘";
	}
	if (pos == 0)
	{
		std::cout << "├";
		for(size_t i = 0; i < s; ++i){
			std::cout << "───";
			if (i < s-1) std::cout << "┼";
		}
		std::cout << "┤";
	}
	std::cout << std::endl;
}
void Map::Draw() const{
	DrawHorB(1);
	size_t j = 0;
	for (const auto& i : _M){
		DrawLine(i);
		++j;
		if (j < _M.size()) DrawHorB(0);
	}
	DrawHorB(2);
}
