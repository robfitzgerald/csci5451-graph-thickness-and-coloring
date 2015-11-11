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

	void tryGraphColoring(int);

private:
	bool populateMatrix();
	int n;
	//int subGraphSize;
	int* r;
	int** adjacencyMatrix;
	int matrixSize;
	int* vertexColor;
	int rSize;
};

void consoleLogMatrix(int**,int);

#endif