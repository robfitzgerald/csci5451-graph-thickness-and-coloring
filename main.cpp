#include <iostream>
#include "chromaticNumber.h"

int main(int argc, char** argv) {

	if (argc < 3) {
		std::cout << "usage: CnKr <cycle length> r1 r2 .. rn \n\n";
		return 1;
	}

	unsigned vertices = argc - 2;
	int r [vertices];

	for (int i = 0; i < vertices; ++i) {
		r[i] = atoi(argv[i+2]);
	}

	int n = atoi(argv[1]);

	std::cout << "n is " << n << std::endl;
	for (int i = 0; i < vertices; ++i) {
		std::cout << "r[" << i << "] is " << r[i] << std::endl;
	}

	chromaticNumber(n,r,vertices);

	return 0;
}