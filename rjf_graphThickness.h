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
		
		int arraySize = 0;
		if (checkIfRValuesAreEqual (inputRArray, inputRSize)) {
			// just multiply r[0] * n
			arraySize = n * r[0];
			std::cout << "arraySize (n * r[0]) is " << arraySize << "\n";
		} else {
			// add all values in r[]
			for (int i = 0; i < rSize; ++i) {
				arraySize += inputRArray[i];
			}
			std::cout << "arraySize (sum) is " << arraySize << "\n";
		}

		subGraphSize = findLargestR(inputRArray, inputRSize);
		std::cout << "subGraphSize is " << subGraphSize << "\n";

		// instantiate adjacency matrix and vertex coloring array
		// and initialize everything EVERRRRYTHING to zero
		adjacencyMatrix = new int*[arraySize];
		for(int i = 0; i < arraySize; ++i) {
			adjacencyMatrix[i] = new int[arraySize];
			for (int j = 0; j < arraySize; ++j) {
				adjacencyMatrix[i][j] = 0;
			}
		}
		vertexColor = new int[arraySize];
		for (int i = 0; i < arraySize; ++i) {
			vertexColor[i] = 0;
		}

	}

private:
	int n;
	int subGraphSize;
	int* r;
	int** adjacencyMatrix;
	int* vertexColor;
	int rSize;
};

#endif