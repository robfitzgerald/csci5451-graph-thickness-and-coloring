#include "rjf_graphMatrix.h"
#include <iostream>

const int kEdge = 100;
const int cEdge = 200;

graphMatrix::graphMatrix(int inputN, int* inputRArray, int inputRSize): n(inputN), r(inputRArray), rSize(inputRSize) {
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

int graphMatrix::stepByCycleVertex(int cycleVertex) {
	int step = 0;
	for (int i = 0; i < cycleVertex; ++i) {
		step += r[i];
	}
	return step;
}

int graphMatrix::subGraphSize(int cycleVertex) {
	return r[cycleVertex];
}

bool graphMatrix::populateMatrix() {

	// of the K-form (so, all adjacent except KvKv adjacencies)
	for (int i = 0; i < n; ++i) {
		int startSubG = stepByCycleVertex(i);
		int endSubG = startSubG + subGraphSize(i);
		for (int j = startSubG; j < endSubG; ++j) {
			for (int k = startSubG; k < endSubG; ++k) {
				if (j != k) {
					adjacencyMatrix[j][k] = kEdge;
				}
			}
		}
	}
	// connections from K to its right-neighbors
	for (int i = 0; i < n; ++i) {
		int rightNeighbors = ((i + 1) % n);
		int leftNeighbors = (((i + 5) - 1) % n);
		int startSubG = stepByCycleVertex(i);
		int endSubG = startSubG + subGraphSize(i);
		//std::cout << "i: " << i << ", r: " << rightNeighbors << ", l" << leftNeighbors << "\n";
		int startRightSubG = stepByCycleVertex(rightNeighbors);
		int endRightSubG = startRightSubG + subGraphSize(rightNeighbors);
		int startLeftSubG = stepByCycleVertex(leftNeighbors);
		int endLeftSubG = startLeftSubG + subGraphSize(leftNeighbors);

		for (int j = startRightSubG; j < endRightSubG; ++j) {
			for (int k = startSubG; k < endSubG; ++k) {
				adjacencyMatrix[j][k] = cEdge;
			}
		}
		for (int j = startLeftSubG; j < endLeftSubG; ++j) {
			for (int k = startSubG; k < endSubG; ++k) {
				adjacencyMatrix[j][k] = cEdge;
			}
		}
	}
	return true;
}

void graphMatrix::tryGraphColoring(int x) {


	consoleLogMatrix(adjacencyMatrix,matrixSize);
}

void consoleLogMatrix(int** m, int s) {
	std::cout << "-----Matrix Output-----\n";
	for (int i = 0; i < s; ++i) {
		std::cout << "[ ";
		for (int j = 0; j < s; ++j) {
			std::cout << " " << m[i][j] << " ";
		}
		std::cout << " ]\n";
	}
	std::cout << std::endl;
}