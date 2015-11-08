#include <iostream>
#include "chromaticNumber.h"



int main(int argc, char** argv) {

	/* command line input processing */

	if (argc < 3) {
		std::cout << "usage: CnKr <cycle length> r1 r2 .. rn \n\n";
		return 1;
	}
	unsigned rSize = argc - 2;
	int r [rSize];
	for (int i = 0; i < rSize; ++i) {
		r[i] = atoi(argv[i+2]);
	}
	int n = atoi(argv[1]);

	/* chromatic number */

	int c = chromaticNumber(n,r,rSize);

	/* thickness */

	/* output */

	std::cout << "Graph of C" << n << "[";
	for (int i = 0; i < rSize; ++i) {
		std::cout << r[i];
		if (!(rSize - 1 == i)) {
			std::cout << ",";
		}
	}
	std::cout << "]:" << std::endl;
	std::cout << "chromatic number is " << c << "\n" << std::endl;

	return 0;
}