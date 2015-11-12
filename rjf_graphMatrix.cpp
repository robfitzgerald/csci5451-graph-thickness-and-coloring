#include "rjf_graphMatrix.h"
#include <iostream>

const int UNCOLORED_EDGE = 999;

graphMatrix::graphMatrix(int inputN, int* inputRArray, int inputRSize): n(inputN), r(inputRArray), rSize(inputRSize) {
	// find # of vertices in cycle, multiply against # of vertices in subgraphs
	// or add # of vertices in subgraphs together if defined.
	
	matrixSize = 0;
	if (checkIfRValuesAreEqual (inputRArray, inputRSize)) {
		// just multiply r[0] * n
		matrixSize = n * r[0];
	} else {
		// add all values in r[]
		for (int i = 0; i < rSize; ++i) {
			matrixSize += inputRArray[i];
		}
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

int graphMatrix::largestSubGraph() {
	int largestValue = -1;
	int largestIndex = -1;
	for (int i = 0; i < n; ++i) {
		int sSize = subGraphSize(i);
		if (sSize > largestValue) {
			largestValue = sSize;
			largestIndex = i;
		}
	}
	return largestIndex;
}

bool graphMatrix::populateMatrix() {

	// of the K-form (so, all adjacent except KvKv adjacencies)
	for (int i = 0; i < n; ++i) {
		int startSubG = stepByCycleVertex(i);
		int endSubG = startSubG + subGraphSize(i);
		for (int j = startSubG; j < endSubG; ++j) {
			for (int k = startSubG; k < endSubG; ++k) {
				if (j != k) {
					adjacencyMatrix[j][k] = UNCOLORED_EDGE;
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
				adjacencyMatrix[j][k] = UNCOLORED_EDGE;
			}
		}
		for (int j = startLeftSubG; j < endLeftSubG; ++j) {
			for (int k = startSubG; k < endSubG; ++k) {
				adjacencyMatrix[j][k] = UNCOLORED_EDGE;
			}
		}
	}
	return true;
}

void graphMatrix::tryGraphColoring(int x) {
	// set up matrix labelled with uncolored edges
	populateMatrix();

	if ((n % 2) == 0) {
		// EVEN-SIZED CYCLE
		// figure out if the largest sub graph is an even or odd numbered cycle vertex
		bool largestHasEvenIndex = ((largestSubGraph() % 2) == 0);
		int largestSize = findLargestR(r,rSize);
		for (int cycle = 0; cycle < n; ++cycle) {
			// iterating through cycle vertices..
			int startSubGraph = stepByCycleVertex(cycle);
			//std::cout << "moving to step position " << startSubGraph << "\n";
			//std::cout << "entering for loop bounded by " << subGraphSize(cycle) << "\n";
			//int endSubGraph = endSubGraph(cycle);
			for (int i = 0; i < subGraphSize(cycle); ++i) {
				int thisRow = i + startSubGraph;
				if (((cycle % 2) == 0) == largestHasEvenIndex) {
					// larger group, we make sure to color it by the larger color subset.
					int thisColor = i + 1;
					//std::cout << thisRow << " is in larger group, using color " << thisColor << "\n";
					for (int j = 0; j < matrixSize; ++j) {
						if (adjacencyMatrix[j][thisRow] == UNCOLORED_EDGE) {
							adjacencyMatrix[j][thisRow] = thisColor;
						}
					}
					adjacencyMatrix[thisRow][thisRow] = thisColor;
				} else {
					// smaller group
					int thisColor = i + 1 + largestSize;
					//std::cout << thisRow << " is in smaller group, using color " << thisColor << "\n";
					for (int j = 0; j < matrixSize; ++j) {
						if (adjacencyMatrix[j][thisRow] == UNCOLORED_EDGE) {
							adjacencyMatrix[j][thisRow] = thisColor;
						}
					}
					adjacencyMatrix[thisRow][thisRow] = thisColor;
				}	
			}
		}
	} else {
		// ODD-SIZED CYCLE
			// for each vertex
		for (int i = 0; i < matrixSize; ++i) {
			bool colors [(x+1)];
			for (int i = 1; i <= x; ++i) {
				colors[i] = true;
			}	

			// find adjacent edges
			for (int j = 0; j < matrixSize; ++j) {
				if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != UNCOLORED_EDGE) {
					int foundColor = adjacencyMatrix[i][j];
					colors[foundColor] = false;
				}
			}
			// i have now removed all used colors from color[] for this vertex.
			// set the diagonal with this i's color.
			for (int newC = 1; newC <= x; ++newC) {
				if (colors[newC] == true) {
					adjacencyMatrix[i][i] = newC;
					for (int j = 0; j < matrixSize; ++j) {
						if (adjacencyMatrix[j][i] == UNCOLORED_EDGE) {
							adjacencyMatrix[j][i] = newC;
						}
					}
					newC = x + 1;  // break for loop
				}
			}
		}
	}

	std::cout << "-----Attempting a Graph Coloring with " << x << " colors-----\n";
	consoleLogMatrix(adjacencyMatrix,matrixSize);
}

void consoleLogMatrix(int** m, int s) {
	std::cout << "-----Adjacency Matrix-----\n";
	for (int i = 0; i < s; ++i) {
		std::cout << "[ ";
		for (int j = 0; j < s; ++j) {
			int number = m[i][j];
			if (i == j) { 
				number = 0;  // clear diagonals for presentation
			}
			if (number < 10) {
				std::cout << " ";  // pad numbers less than 10
			} 
			if (number == UNCOLORED_EDGE) {
				std::cout << "  / ";  // error!
			} else {
				std::cout << " " << number << " ";
			}
		}
		std::cout << " ]\n";
	}
	std::cout << std::endl;
}