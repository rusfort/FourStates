//============================================================================
// Name        : FourStates.cpp
// Author      : Nick Rusfort (Nikolay Kozakov)
// Version     :
// Copyright   : Open-source
// Description : Some kind of AI states which only purpose is to take over the map
//============================================================================

#include <iostream>
#include <vector>
#include "world.h"
using namespace std;

int main() {
	cout << "Starting..." << endl << endl;
	World W{7, 5};
	W.getmap().Draw();
	W.Process();
	W.getmap().Draw();
	cout << "State power is " << W(2).getpower() << endl;
	cout << "Cell has " << NB_contains(NBhood(W.getmap(), W.getmap().getcell(2, 7)), 1) << " neighbours of owner 1" << endl;
	cout << "Cell has " << NB_contains(NBhood(W.getmap(), W.getmap().getcell(2, 7)), 2) << " neighbours of owner 2" << endl;
	cout << "Cell has " << NB_contains(NBhood(W.getmap(), W.getmap().getcell(9, 6)), 1) << " neighbours of owner 1" << endl;
	cout << "Cell has " << NB_contains(NBhood(W.getmap(), W.getmap().getcell(9, 6)), 4) << " neighbours of owner 4" << endl;
	return 0;
}
