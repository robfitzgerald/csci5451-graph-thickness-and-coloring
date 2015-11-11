#include "rjf_graphThickness.h"
#include <iostream>

int thickness::stepByCycleVertex(int cycleVertex) {
	int step = 0;
	for (int i = 0; i < cycleVertex; ++i) {
		step += r[i];
	}
	return step;
}

int thickness::subGraphSize(int cycleVertex) {
	return r[cycleVertex];
}

bool thickness::populateMatrix() {

	// of the K-form (so, all adjacent except KvKv adjacencies)
	for (int i = 0; i < n; ++i) {
		int startSubG = stepByCycleVertex(i);
		int endSubG = startSubG + subGraphSize(i);
		for (int j = startSubG; j < endSubG; ++j) {
			for (int k = startSubG; k < endSubG; ++k) {
				if (j != k) {
					adjacencyMatrix[j][k] = 1;
				}
			}
		}
	}
	// connections from K to its right-neighbors
	for (int i = 0; i < n; ++i) {
		int rightNeighbors = ((i + 1) % n);
		int leftNeighbors = (((i + 5) - 1) % n);
		std::cout << "i: " << i << ", r: " << rightNeighbors << ", l" << leftNeighbors << "\n";
	}

	consoleLogMatrix(adjacencyMatrix,matrixSize);

	return true;
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