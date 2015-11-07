#include <iostream>

int main(int argc, char** argv) {

	if (argc < 3) {
		std::cout << "usage: CnKr <cycle length> <complete graph size> \n\n";
		return 1;
	}

	int n = atoi(argv[1]);
	int r = atoi(argv[2]);

	std::cout << "n is " << n << ", r is " << r << std::endl;

	return 0;
}