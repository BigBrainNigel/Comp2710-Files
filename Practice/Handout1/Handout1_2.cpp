#include <iostream>
using namespace std;

int square1(int n) {

	n *= n;
	return n;

}

void square2(int *n) {

	*n *= *n;

}

void square3(int &n) {

	n *= n;

}

int main() {

	int n1 = 8;
	square1(n1);
	std::cout << "Square of n1: " << n1 << "\n";

	int n2 = 8;
	square2(&n2);
	std::cout << "Square of n2: " << n2 << "\n";

	int n3 = 8;
	square3(n3);
	std::cout << "Square of n3: " << n3 << "\n";	

}
