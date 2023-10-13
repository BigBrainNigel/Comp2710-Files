// Gregory H. Walker; ghw0012
// project3_Walker_ghw0012.cpp
// Learning to implement and make use of streams and file I/O, arrays, functions, unit testing, and a simple algorithms.
// Compile by running "g++ -std=c++11 project3_Walker_ghw0012.cpp" in your command line, then run "./a.out" to begin the program. 
// 	When asked for a file name, put just the file name (e.g. input1.txt) if it is in the same directory as the project file. Else, put in the entire path to the file (e.g. test_case_1/input1.txt).
// REFERNCES:
//      (1) Used project example code as a guide and general layout for the formatting of this project. 
//      (2) Used the answer from the user "Kryler" on StackOverflow to fix compilation errors. He said to add "-std=c++11" to compilation command.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_SIZE = 100;
string fileName;

int readFile(int inputArray[], ifstream& inputStream) {
	
	int i = 0;
	
	if (!inputStream.is_open()) {

		std::cout << "File cannot be opened.\n";
		exit(1);

	}

	inputStream >> inputArray[i];
	while (!inputStream.eof()) {

		i++;
		inputStream >> inputArray[i];
	}
	
	std::cout << "The list of " << i << " numbers in file " << fileName << " is: \n";

	for (int j = 0; j < i; j++) {

		cout << inputArray[j] << endl;

	}

	return i;

}

void writeFile(int outArr[], int outArrSize) {

        ofstream outputStream;

        std::cout << "\nEnter the output file name: ";
        std::cin >> fileName;
        outputStream.open(fileName);

        if (!outputStream.is_open()) {

                std::cout << "File cannot be opened.\n";

        }
        else {

                for (int i = 0; i < outArrSize; i++) {

                        outputStream << outArr[i] << endl;

                }

        }

        outputStream.close();

	std::cout << "\n*** Please check the new file - " << fileName << " ***" << "\n*** Goodbye. ***\n";

}

int sort (int inputArr1[], int inputArr1Size, int inputArr2[], int inputArr2Size) {
		
	int outputArr[MAX_SIZE], outputSize = 0, k;
	
	//Loading elements of inputArr1 into outputArr
	for (int i = 0; i < inputArr1Size; i++) {

		outputArr[i] = inputArr1[i];
		outputSize++;

	}
	
	//Loading elements of inputArr2 into outputArr
	k = outputSize;
	for (int i = 0; i < inputArr2Size; i++) {
		
		outputArr[k] = inputArr2[i];
		k++;
		outputSize++;

	}
	
	//Sorting output array
	for (int i = 0; i < outputSize; i++) {

		for (int j = i + 1; j < outputSize; j++) {

			if (outputArr[j] < outputArr[i]) {

				int temp = outputArr[i];
				outputArr[i] = outputArr[j];
				outputArr[j] = temp;

			}

		}

	}
	
	//Outputting sorted list of elements
	std::cout << "\nThe sorted list of " << outputSize << " numbers is: ";
	for (int i = 0; i < outputSize; i++) {

		std::cout << outputArr[i] << " ";

	}
	std::cout << "\n";

	//Writing output array to an output file
	writeFile(outputArr, outputSize);

	return outputSize;
}

int main() {

        ifstream inputStream;
        int inputData, inputArr1Size, inputArr2Size, outArrSize, inputArr1[MAX_SIZE], inputArr2[MAX_SIZE];

        std::cout << "*** Welcome to Hayden's sorting program ***\n";

	//Input for the first file
	std::cout << "Enter the first input file name: ";
        std::cin >> fileName;
        inputStream.open(fileName);
        inputArr1Size = readFile(inputArr1, inputStream);
        inputStream.close();

	//Input for the second file
	std::cout << "\nEnter the second input file name: ";
	std::cin >> fileName;
	inputStream.open(fileName);
	inputArr2Size = readFile(inputArr2, inputStream);
	inputStream.close();

	//Merging and sorting both input arrays, then output it to a write file
	outArrSize = sort(inputArr1, inputArr1Size, inputArr2, inputArr2Size);
	

}


