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
		for (int i = 0; i < 5; ++i) State_Powers.push_back(0);
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

std::list<Neighbour> NBhood(const Map& M, const Cell& C){
	std::list<Neighbour> NB;
	int x0 = C.col;
	int y0 = C.row;
	int sx = M.getsizeX() - 1;
	int sy = M.getsizeY() - 1;

	if (x0 == 0){ //left side of the map
		if (y0 == 0){
			NB.push_back(ConvCellToNB(M.getcell(0, 1), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(1, 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(1, 0), NeighbourType::ORT));
		} else if (y0 == sy) {
			NB.push_back(ConvCellToNB(M.getcell(sy - 1, 0), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(sy - 1, 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(sy, 1), NeighbourType::ORT));
		} else {
			NB.push_back(ConvCellToNB(M.getcell(y0 - 1, 0), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(y0 - 1, 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(y0, 1), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(y0 + 1, 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(y0 + 1, 0), NeighbourType::ORT));
		}
		return NB;
	}
	if (x0 == sx){ //right side of the map
		if (y0 == 0){
			NB.push_back(ConvCellToNB(M.getcell(0, sx - 1), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(1, sx - 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(1, sx), NeighbourType::ORT));
		} else if (y0 == sy) {
			NB.push_back(ConvCellToNB(M.getcell(sy - 1, sx), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(sy - 1, sx - 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(sy, sx - 1), NeighbourType::ORT));
		} else {
			NB.push_back(ConvCellToNB(M.getcell(y0 - 1, sx), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(y0 - 1, sx - 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(y0, sx - 1), NeighbourType::ORT));
			NB.push_back(ConvCellToNB(M.getcell(y0 + 1, sx - 1), NeighbourType::DIAG));
			NB.push_back(ConvCellToNB(M.getcell(y0 + 1, sx), NeighbourType::ORT));
		}
		return NB;
	}
	if (y0 == 0){ //top side without corners
		NB.push_back(ConvCellToNB(M.getcell(0, x0 - 1), NeighbourType::ORT));
		NB.push_back(ConvCellToNB(M.getcell(1, x0 - 1), NeighbourType::DIAG));
		NB.push_back(ConvCellToNB(M.getcell(1, x0), NeighbourType::ORT));
		NB.push_back(ConvCellToNB(M.getcell(1, x0 + 1), NeighbourType::DIAG));
		NB.push_back(ConvCellToNB(M.getcell(0, x0 + 1), NeighbourType::ORT));
		return NB;
	}
	if (y0 == sy){ //bottom side without corners
		NB.push_back(ConvCellToNB(M.getcell(sy, x0 - 1), NeighbourType::ORT));
		NB.push_back(ConvCellToNB(M.getcell(sy - 1, x0 - 1), NeighbourType::DIAG));
		NB.push_back(ConvCellToNB(M.getcell(sy - 1, x0), NeighbourType::ORT));
		NB.push_back(ConvCellToNB(M.getcell(sy - 1, x0 + 1), NeighbourType::DIAG));
		NB.push_back(ConvCellToNB(M.getcell(sy, x0 + 1), NeighbourType::ORT));
		return NB;
	}
	//default position in the middle:
	NB.push_back(ConvCellToNB(M.getcell(y0, x0 - 1), NeighbourType::ORT));
	NB.push_back(ConvCellToNB(M.getcell(y0 - 1, x0 - 1), NeighbourType::DIAG));
	NB.push_back(ConvCellToNB(M.getcell(y0 - 1, x0), NeighbourType::ORT));
	NB.push_back(ConvCellToNB(M.getcell(y0 - 1, x0 + 1), NeighbourType::DIAG));
	NB.push_back(ConvCellToNB(M.getcell(y0, x0 + 1), NeighbourType::ORT));
	NB.push_back(ConvCellToNB(M.getcell(y0 + 1, x0 + 1), NeighbourType::DIAG));
	NB.push_back(ConvCellToNB(M.getcell(y0 + 1, x0), NeighbourType::ORT));
	NB.push_back(ConvCellToNB(M.getcell(y0 + 1, x0 - 1), NeighbourType::DIAG));

	return NB;
}

size_t NB_contains(const std::list<Neighbour>& NB, int owner){
	size_t n = 0;
	for (auto i : NB){
		if (i.owner_ == owner) ++n;
	}
	return n;
}

bool NB_sameowner(const std::list<Neighbour>& NB, int owner){
	return (NB_contains(NB, owner) == NB.size());
}
