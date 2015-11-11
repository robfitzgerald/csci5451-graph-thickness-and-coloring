#include "rjf_graphThickness.h"
#include <iostream>

int main () {

	int subGraphs [5] = {4,4,4,4,3};
	thickness p1 (5, subGraphs, 5);
	std::cout << "stepByCycleVertex(2): " << p1.stepByCycleVertex(2) << std::endl;
	std::cout << "subGraphSize(2) should be 3: " << p1.subGraphSize(2) << std::endl;

	//int subGraphs2 [1] = {3};
	//thickness p2 (5, subGraphs2, );

	return 0;
}