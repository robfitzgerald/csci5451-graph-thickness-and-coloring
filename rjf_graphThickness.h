#ifndef graphThickness_h
#define graphThickness_h
#include "chromaticNumber.h"
#include <iostream>


class thickness {
public:
	thickness(int inputN, int* inputRArray, int inputRSize): n(inputN), r(inputRArray), rSize(inputRSize)
	{
		// find # of vertices in cycle, multiply against # of vertices in subgraphs
		// or add # of vertices in subgraphs together if defined.
		
		matrixSize = 0;
		if (checkIfRValuesAreEqual (inputRArray, inputRSize)) {
			// just multiply r[0] * n
			matrixSize = n * r[0];
			std::cout << "matrixSize (n * r[0]) is " << matrixSize << "\n";
		} else {
			// add all values in r[]
			for (int i = 0; i < rSize; ++i) {
				matrixSize += inputRArray[i];
			}
			std::cout << "matrixSize (sum) is " << matrixSize << "\n";
		}

		// this may not be used, but, it's the largest subgraph size
		// could be helpful if we set up the adj. matrix to be of length
		// n * subGraphSize, so there is a consistent step size between
		// subgraphs on the matrix. but, then there would be the cases of
		// 'this vertex intentionally left blank' which seems dubious.
		//subGraphSize = findLargestR(inputRArray, inputRSize);
		//std::cout << "subGraphSize is " << subGraphSize << "\n";


		// instantiate adjacency matrix and vertex coloring array
		// and initialize everything EVERRRRYTHING to zero
		adjacencyMatrix = new int*[matrixSize];
		for(int i = 0; i < matrixSize; ++i) {
			adjacencyMatrix[i] = new int[matrixSize];
			for (int j = 0; j < matrixSize; ++j) {
				adjacencyMatrix[i][j] = 0;
			}
		}
		vertexColor = new int[matrixSize];
		for (int i = 0; i < matrixSize; ++i) {
			vertexColor[i] = 0;
		}

		populateMatrix();
	}

	// vertex numbering is array index notation
	int stepByCycleVertex(int);
	int subGraphSize(int);

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