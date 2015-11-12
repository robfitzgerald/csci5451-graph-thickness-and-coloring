#ifndef graphMatrix_h
#define graphMatrix_h
#include "chromaticNumber.h"
#include <iostream>


class graphMatrix {
public:
	graphMatrix(int inputN, int* inputRArray, int inputRSize);

	// vertex numbering is array index notation
	int stepByCycleVertex(int);
	int subGraphSize(int);
	int largestSubGraph();

	void tryGraphColoring(int);
	int getValue(int x, int y) {
		return adjacencyMatrix[x][y];
	}
private:
	bool populateMatrix();
	int n;
	int* r;
	int** adjacencyMatrix;
	int matrixSize;
	int rSize;
};

void consoleLogMatrix(int**,int);

#endif