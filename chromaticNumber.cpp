#include <iostream>
#include "chromaticNumber.h"

int chromaticNumber(int n, int* r, int rSize) {
	// chromatic number of Cn[r1,r2..rn]
	// is found by our calculation:

	// if n is even:
	//   if all rn are the same
	//     return 2 * r
	//   if not, find the largest r sizes. ceiling(largest r sizes)

	// if n is odd:  (the assigned problem)
	//   if all rn are the same
	//     return 2r + ceiling(r / 2)
	//   if not all rn are the same
	//     ..

	if (isEven(n)) {
		
	}

	return 0;
}

bool isEven (int n) {
	return ((n % 2) == 0);
}