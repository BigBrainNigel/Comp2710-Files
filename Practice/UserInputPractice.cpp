
#include <iostream>

int main() {

	int initialLoan = 0;
	int paymentTowardsLoan = 0;

	std::cout << "Enter initial loan amount: ";
	std::cin >> initialLoan;

	std::cout << "Enter amount being paid toward loan: ";
	std::cin >> paymentTowardsLoan;
        std::cout << "Thank you! Balance left on your loan: " << (initialLoan - paymentTowardsLoan) << "\n";	

}
