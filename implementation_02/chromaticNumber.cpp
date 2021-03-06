#include <iostream>
#include "math.h"
#include "chromaticNumber.h"

const int SENTINEL = 99999;


/////////////////////////////////////////////
//  n is cycle length, 
//  r[] is list of [r1, r2,.. rn], 
//  rSize should equal n silly
//  returns: chromatic number of the graph
//    Cn[Kr]
/////////////////////////////////////////////
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

       // edge case, n == 1
       if (n == 1) return r[0];

	int chromaticResult = 0;
	if (isEven(n)) {
		std::cout << "add largest and second largest r values.\n";
		if (rSize == 1) {
			chromaticResult = r[0] * 2;
		} else {
			chromaticResult = findTwoLargestRs(r, rSize);
		}
	} else {  /* is odd */
		if (checkIfRValuesAreEqual(r, rSize)) {
			chromaticResult = 2 * r[0] + ceil(r[0] / 2.0);
		} else {
			//int lowestR = findLowestR(r, rSize);
			//chromaticResult = 2 * lowestR + ceil(lowestR / 2.0);
			chromaticResult = findTwoLargestUniqueRsAndEvaluate(r, rSize);
			std::cout << "hmm. this may need to be based on the independence number\n";
		}
	}
	return chromaticResult;
}



bool isEven (int n) {
	return ((n % 2) == 0);
}



bool checkIfRValuesAreEqual (int* r, int rSize) {
	int previousRValue = r[0];
	for (int i = 1; i < rSize; i++) {
		if (r[i] != previousRValue) {
			return false;
		}
		previousRValue = r[i];
	}
	return true;
}


int findLargestR(int* r, int rSize) {
	int largest = r[0[;
	for (int i = 1; i < rSize; ++i) {
		if (largest <= r[i]) {
			largest = r[i];
		}
	}
	return largest;
}



int findTwoLargestRs(int* r, int rSize) {
	int largest = r[0[;
	int secondLargest = -1;
	for (int i = 1; i < rSize; ++i) {
		if (largest <= r[i]) {
			secondLargest = largest;
			largest = r[i];
		} else if (secondLargest <= r[i]) {
			secondLargest = r[i];
		}
	}
	return largest + secondLargest;
}



int findTwoLargestUniqueRsAndEvaluate(int* r, int rSize) {
	int largest = r[0];
	int secondLargest = -1;
	for (int i = 0; i < rSize; ++i) {
		if (largest < r[i]) {
			secondLargest = largest;
			largest = r[i];
		} else if (secondLargest < r[i]) {
			secondLargest = r[i];
		}
	}
	// matt's equation for chromatic value of odd cycle and outliers in [r1,r2..]
	return largest + largest + secondLargest - floor(secondLargest / 2);
}



int findLowestR (int* r, int rSize) {
	int lowest = SENTINEL;
	for (int i = 0; i < rSize; ++i) {
		if (lowest > r[i]) {
			lowest = r[i];
		}
	}
	return lowest;
}
