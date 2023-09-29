#include <iostream>
using namespace std;

int main() {

	while (true) {

		int i;
		std::cin >> i;

		switch (i) {

			case 1:
			case 2:
			case 3:
				std::cout << "inside switch " << i << "\n";
				continue;
			default:
				std::cout << "inside default\n";
				break;

		}

		std::cout << "Bottom of while " << i << endl;
		break;

	}

}
