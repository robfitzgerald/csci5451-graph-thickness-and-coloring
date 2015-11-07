#include <iostream>
#include "chromaticNumber.h"



int main(int argc, char** argv) {

	/* command line input processing */

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

	/* chromatic number */

	int c = chromaticNumber(n,r,vertices);
	std::cout << "chromaticNumber is " << c << "\n\n" << std::endl;

	/* thickness */

	return 0;
}