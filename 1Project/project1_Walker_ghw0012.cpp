//Gregory H. Walker; ghw0012
//project1_Walker_ghw0012.cpp
//Implementing the concept of "flow control" using C++
//Compile by running "g++ project1_Walker_ghw0012.cpp" in your command line, then run "./a.out" to begin the program.
//REFERENCES:
//	(1) Used hint file on Canvas for the general layout of the program.
//	(2) Used the answer from the user "chris" on the StackOverflow thread "c++ How to handle wrong data type input" for clearing and ignoring incorrect user inputs

#include <iostream>
#include <ios>
#include <limits>
using namespace std;

int main() {
	
	//Variable init.
	double loanBal, interestPayment, interestRate, interestRateDivHund, interestTotal,  monthlyPayment, principalVal;
	int month;
	bool flag = true;

	//Formatting for currency values
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//User input. In order for input to be considered valid, it MUST be a number, and it MUST positive, else it will terminate the program. The monthly payment must also be large enough to pay for the interest.

	//Input for the loan amount
	std::cout << "\nLoan amount: ";
	if (!(std::cin >> loanBal) || loanBal < 0) {
		flag = false;
	}

	if (!flag) {
		while (!flag) {
			std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid loan! Input value must be a number and must be greater than zero. Please try again.\n";
 			std::cout << "\nLoan amount: ";
                        if (std::cin >> loanBal && loanBal > 0) {
				flag = true;
			}
		}
	}

	//Input for the interest rate in percent per year
	std::cout << "Interest Rate (% per year): ";
	if (!(std::cin >> interestRate) || interestRate < 0) {
		flag = false;
	}

	if (!flag) {
		while (!flag) {
			std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid interest rate! Input value must be a number and must be greater than zero. Please try again.\n";
                        std::cout << "\nInterest rate (% per year): ";
                        if (std::cin >> interestRate && interestRate > 0) {
                                flag = true;
                        }
		}
	}
	interestRate /= 12;
	interestRateDivHund = interestRate/100;
	interestPayment = loanBal * interestRateDivHund;

	//Input for the monthly payments
	std::cout << "Monthly Payment: ";
	if (!(std::cin >> monthlyPayment) || monthlyPayment < 0 || monthlyPayment <= interestPayment) {
		flag = false;
	}

	if (!flag) {
                while (!flag) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid/insufficient payment! Input value must be a number, must be greater than zero, and cannot be less than or equal to the interest payment. Please try again.\n";
                        std::cout << "\nMonthly Payment: ";
			if (std::cin >> monthlyPayment && monthlyPayment > 0 && monthlyPayment > interestPayment) {
				flag = true;
			}
		}
	}

	std::cout << endl;

	//Amortization Table
	std::cout << "*****************************************************************\n"
		<< "\tAmortization Table\n"
		<< "*****************************************************************\n"
		<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
	
	//Loop used to fill the Amortization Table
	while (loanBal > 0) {
		if (month == 0) {
			std::cout << month++ << "\t$" << loanBal << "\tN/A\tN/A\tN/A\t\tN/A\n";
		}
		else {
			if (loanBal * (1 + interestRateDivHund) < monthlyPayment) {
				interestPayment = loanBal * interestRateDivHund;
				monthlyPayment = loanBal + interestPayment;
				principalVal = monthlyPayment - interestPayment;
				loanBal = loanBal - principalVal;
				interestTotal += interestPayment;
				
				if (loanBal < 1000) {
					std::cout << month++ << "\t$" << loanBal << "\t\t$" << monthlyPayment << "\t" << interestRate << "\t$" << interestPayment << "\t\t$" << principalVal << "\n";
				}
				else {
					std::cout << month++ << "\t$" << loanBal << "\t$" << monthlyPayment << "\t" << interestRate << "\t$" << interestPayment << "\t\t$" << principalVal << "\n";
				}
			
			}
			else if (loanBal * (1 + interestRateDivHund) >= monthlyPayment) {
				interestPayment = loanBal * interestRateDivHund;
                                principalVal = monthlyPayment - interestPayment;
                                loanBal = loanBal - principalVal;
				interestTotal += interestPayment;
				
				if (loanBal < 1000) {
					std::cout << month++ << "\t$" << loanBal << "\t\t$" << monthlyPayment << "\t" << interestRate << "\t$" << interestPayment << "\t\t$" << principalVal << "\n";
				}
				else {
					std::cout << month++ << "\t$" << loanBal << "\t$" << monthlyPayment << "\t" << interestRate << "\t$" << interestPayment << "\t\t$" << principalVal << "\n";
				}

			}


		}

	}

	std::cout << "*****************************************************************\n";
        std::cout << "\nIt takes " << --month << " months to pay off the loan.\n"
                 << "Total interest paid is: $" << interestTotal;
        std::cout << endl << endl;
        return 0;

}
