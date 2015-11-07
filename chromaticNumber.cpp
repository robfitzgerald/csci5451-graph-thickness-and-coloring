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

	int chromaticResult = 0;

	if (isEven(n)) {


		if (checkIfRValuesAreEqual(r, rSize)) {
			std::cout << "r values were all the same\n";
		} else {
			std::cout << "r values were NOT all the same\n";
		}

	} else {
		if (checkIfRValuesAreEqual(r, rSize)) {
			std::cout << "r values were all the same\n";
		} else {
			std::cout << "r values were NOT all the same\n";
		}
	}

	return chromaticResult;
}

bool isEven (int n) {
	return ((n % 2) == 0);
}

bool checkIfRValuesAreEqual (int* r, int rSize) {
	bool rValuesAreAllTheSame = true;
	int previousRValue = r[0];
	for (int i = 1; i < rSize; i++) {
		if (r[i] != previousRValue) {
			rValuesAreAllTheSame = false;
		}
		previousRValue = r[i];
	}
	return rValuesAreAllTheSame;
}