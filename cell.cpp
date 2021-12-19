/*
 * cell.cpp
 *
 *  Created on: 18 дек. 2021 г.
 *      Author: rusfort
 */

#include "cell.h"

Neighbour ConvCellToNB (const Cell& C, NeighbourType t){
	return Neighbour(C.row, C.col, C.owner_, C.status_, t);
}
