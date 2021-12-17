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
	cout << "State power is " << W(2).getpower() << endl;
	return 0;
}
