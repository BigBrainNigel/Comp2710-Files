// Gregory H. Walker; ghw0012
// project2_Walker_ghw0012.cpp
// Learning to implement while and do-while statements, custom defined functions, test drivers, assert(), and random number generators.
// Compile by running "g++ project2_Walker_ghw0012.cpp" in your command line, then run "./a.out" to begin the program.
// REFERNCES:
// 	(1) Used the project outline to get a general layout for the code, and borrowed the function names, as well as some of the variable names.

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <iomanip>
using namespace std;

const int AACCURACY = 33, BACCURACY = 50, CACCURACY = 100, NUMRUNS = 10000;
int aaronShotsFired = 0;
bool aShotAt, bShotAt, cShotAt, aAlive, bAlive, cAlive;
float aWinRate, aWinRateStrat1, bWinRate, cWinRate, aWins = 0, bWins = 0, cWins = 0;

//Generates a random number between 0 and 100 and uses that to determine if the fired shot hits, depending on the shooters accuracy. Seeded with srand(time(0)) found in the main() function.
bool targetHit(int shotAccuracy) {

        int randNum;
        randNum = rand() % 100;

        if (randNum < shotAccuracy) {
                return true;
        }

        return false;

}

//Detects if two people are still alive and returns a bool value with the result.
bool atLeastTwoAlive (bool aAlive, bool bAlive, bool cAlive) {
	
	int numAlive = 0;

	if (aAlive) {
		numAlive++;
	}
	if (bAlive) {
		numAlive++;
	}
	if (cAlive) {
		numAlive++;
	}
	
	if (numAlive >= 2) {
		return true;
	}

	return false;

}

void atLeastTwoAliveTest (void) {

	std::cout << "\nUnit Testing 1: Function - atLeastTwoAlive()\n";

	//Case 1
	std::cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == atLeastTwoAlive(true, true, true));
	std::cout << "\tCase passed ...\n";
	
	//Case 2
	std::cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == atLeastTwoAlive(false, true, true));
	std::cout << "\tCase passed ...\n";

	//Case 3
        std::cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
        assert(true == atLeastTwoAlive(true, false, true));
        std::cout << "\tCase passed ...\n";

	//Case 4
        std::cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
        assert(true == atLeastTwoAlive(true, true, false));
        std::cout << "\tCase passed ...\n";

	//Case 5
        std::cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
        assert(false == atLeastTwoAlive(false, false, true));
        std::cout << "\tCase passed ...\n";

	//Case 6
        std::cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
        assert(false == atLeastTwoAlive(false, true, false));
        std::cout << "\tCase passed ...\n";

	//Case 7
        std::cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
        assert(false == atLeastTwoAlive(true, false, false));
        std::cout << "\tCase passed ...\n";

	//Case 8
        std::cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
        assert(false == atLeastTwoAlive(false, false, false));
        std::cout << "\tCase passed ...\n";

}

//Determines who Aaron attempts to shoot in Strategy 1.
void aaronShoots1 (bool& bAlive, bool& cAlive) {

	if (cAlive) {

		cShotAt = true;

		if (targetHit(AACCURACY)) {
			cAlive = false;
		}
	}
	else if (bAlive) {

		bShotAt = true;

		if (targetHit(AACCURACY)) {
			bAlive = false;
		}

	}

}

void aaronShoots1Test (void) {
	
	std::cout << "Unit Test 2: Function - aaronShoots1(bAlive, cAlive)\n";

	//Case 1
	std::cout << "\tCase 1: Bob alive, Charlie alive\n";
	aaronShoots1(bAlive = true, cAlive = true);
	assert(cShotAt == true);
	std::cout << "\t\tAaron is shooting at Charlie\n";

	//Case 2
	std::cout << "\tCase 2: Bob dead, Charlie alive\n";
	aaronShoots1(bAlive = false, cAlive = true);
	assert(cShotAt == true);
	std::cout << "\t\tAaron is shooting at Charlie\n";

	//Case 3
	std::cout << "\tCase 3: Bob alive, Charlies dead\n";
	aaronShoots1(bAlive =true, cAlive = false);
	assert(bShotAt == true);
	std::cout << "\t\tAaron is shooting at Bob\n";

}

//Determines who Bob attempts to shoot
void bobShoots (bool& aAlive, bool& cAlive) {

	if (cAlive) {

		cShotAt = true;

		if (targetHit(BACCURACY)) {	
			cAlive = false;
		}

	}
	else if (aAlive) {

		aShotAt = true;

		if (targetHit(BACCURACY)) {
			aAlive = false;
		}

	}

}

void bobShootsTest (void) {

	std::cout << "Unit Test 3: Function - bobShoots(aAlive, cAlive)\n";

	//Case 1
	std::cout << "\tCase 1: Aaron alive, Charlie alive\n";
	bobShoots(aAlive = true, cAlive = true);
	assert(cShotAt == true);
	std::cout << "\t\tBob is shooting at Charlie\n";

	//Case 2
        std::cout << "\tCase 2: Aaron dead, Charlie alive\n";
        bobShoots(aAlive = false, cAlive = true);
        assert(cShotAt == true);
        std::cout << "\t\tBob is shooting at Charlie\n";

	//Case 3
        std::cout << "\tCase 3: Aaron alive, Charlie dead\n";
        bobShoots(aAlive = true, cAlive = false);
        assert(aShotAt == true);
        std::cout << "\t\tBob is shooting at Aaron\n";

}

//Determines who Charlie attempts to shoot
void charlieShoots (bool& aAlive, bool& bAlive) {

	if (bAlive) {

		bShotAt = true;

		if (targetHit(CACCURACY)) {
			bAlive = false;
		}

	}
	else if (aAlive) {

		aShotAt=true;

		if (targetHit(CACCURACY)) {
			aAlive = false;
		}

	}

}

void charlieShootsTest (void) {

	std::cout << "Unit Test 4: Function - charlieShoots(aAlive, bAlive)\n";

	//Case 1:
	std::cout << "\tCase 1: Aaron alive, Bob alive\n";
	charlieShoots(aAlive = true, bAlive = true);
	assert(bShotAt == true);
	std::cout << "\t\tCharlie is shooting at Bob\n";

	//Case 2:
        std::cout << "\tCase 2: Aaron dead, Bob alive\n";
        charlieShoots(aAlive = false, bAlive = true);
        assert(bShotAt == true);
        std::cout << "\t\tCharlie is shooting at Bob\n";

	//Case 3:
        std::cout << "\tCase 3: Aaron alive, Bob dead\n";
        charlieShoots(aAlive = true, bAlive = false);
        assert(bShotAt == true);
        std::cout << "\t\tCharlie is shooting at Aaron\n";

}

//Determines who Aaron attempts to shoot in Strategy 2. Always misses the first shot.
void aaronShoots2 (bool& bAlive, bool& cAlive) {

	if (aaronShotsFired > 0) {

		if (cAlive) {

			cShotAt = true;

			if (targetHit(AACCURACY)) {
				cAlive = false;
			}

		}
		else if (bAlive) {

			bShotAt = true;

			if (targetHit(AACCURACY)) {
				bAlive = false;
			}

		}	

	}
	else {
		cShotAt = false;
		bShotAt = false;
	}

	aaronShotsFired++;

}

void aaronShoots2Test() {

	std::cout << "Unit Test 5: Function - aaronShoots2(bAlive, cAlive)\n";

	//Case 1
	std::cout << "\tCase 1: Bob alive, Charlie alive\n";
	aaronShoots2(bAlive = true, cAlive = true);
	assert(cShotAt == false && bShotAt == false);
	std::cout << "\t\tAaron intentionally misses his first shot\n" << "\t\tBoth Bob and Charlie are alive\n";

	//Case 2
	std::cout << "\tCase 2: Bob dead, Charlie alive\n";
	aaronShoots2(bAlive = false, cAlive = true);
	assert(cShotAt == true);
	std::cout << "\t\tAaron is shooting at Charlie\n";

	//Case 3
	std::cout << "\tCase 3: Bob alive, Charlie dead\n";
	aaronShoots2(bAlive = true, cAlive = false);
	assert(bShotAt == true);
	std::cout << "\t\tAaron is shooting at Bob\n";

}

//Function for the user to used to decide when to continue on with the program execution.
void cont(void) {

	std::cout << "Press Enter to continue...";
	cin.ignore().get();

}

//Function that loops through and calls all test drivers one by one, breaking between each to get user input on when to continue execution.
void testDrivers(void) {

	for (int i = 1; i <= 5; i++) {

		aShotAt = false;
		bShotAt = false;
		cShotAt = false;

                switch(i) {

                        case 1:
                                atLeastTwoAliveTest();
                                break;
                        case 2:
				aaronShoots1Test();
                                break;
                        case 3:
				bobShootsTest();
                                break;
                        case 4:
				charlieShootsTest();
                                break;
                        case 5:
				aaronShotsFired = 0;
				aaronShoots2Test();
           	                break;

                }

		cont();

	}

}

//Function used to directly test both strategy 1 and 2 against each other. Runs test 10000 times.
void strategyTests(void) {
	
	setprecision(2);

	//Strategy 1
	std::cout << "Ready to test strategy 1 (run " << NUMRUNS << " times):\n";
	cont();

	for (int i = 0; i < NUMRUNS; i++) {
		
		aAlive = true;
		bAlive = true;
		cAlive = true;
		aaronShotsFired = 0;

		while (atLeastTwoAlive(aAlive, bAlive, cAlive)) {

			if (aAlive) {
				aaronShoots1(bAlive, cAlive);
			}
			if (bAlive) {
				bobShoots(aAlive, cAlive);
			}
			if (cAlive) {
				charlieShoots(aAlive, bAlive);
			}

		}

		if (aAlive) {
			aWins++;
		}
		if (bAlive) {
			bWins++;	
		}
		if (cAlive) {
			cWins++;
		}

	}
	
	aWinRate = (aWins / 10000) * 100;
	aWinRateStrat1 = aWinRate;
	bWinRate = (bWins / 10000) * 100;
	cWinRate = (cWins / 10000) * 100;

	std::cout << "Aaron won " << aWins << "/10000 duels or " << aWinRate << "%\n";
	std::cout << "Bob won " << bWins << "/10000 duels or " << bWinRate << "%\n";
	std::cout << "Charlie won " << cWins << "/10000 duels or " << cWinRate << "%\n";

	//Strategy 2
	std::cout << "\nRead to test strategy 2 (run " << NUMRUNS << " times):\n";
	cont();
	
	aWins = 0;
	bWins = 0;
	cWins = 0;

	for (int i = 0; i < NUMRUNS; i++) {

                aAlive = true;
                bAlive = true;
                cAlive = true;
		aaronShotsFired = 0;

                while (atLeastTwoAlive(aAlive, bAlive, cAlive)) {

                        if (aAlive) {
                                aaronShoots2(bAlive, cAlive);
                        }
                        if (bAlive) {
                                bobShoots(aAlive, cAlive);
                        }
                        if (cAlive) {
                                charlieShoots(aAlive, bAlive);
                        }


                }

                if (aAlive) {
                        aWins++;
                }
                if (bAlive) {
                        bWins++;
                }
                if (cAlive) {
                        cWins++;
                }

        }

	aWinRate = (aWins / 10000) * 100;
        bWinRate = (bWins / 10000) * 100;
        cWinRate = (cWins / 10000) * 100;

        std::cout << "Aaron won " << aWins << "/10000 duels or " << aWinRate << "%\n";
        std::cout << "Bob won " << bWins << "/10000 duels or " << bWinRate << "%\n";
        std::cout << "Charlie won " << cWins << "/10000 duels or " << cWinRate << "%\n";
	
	if (aWinRate > aWinRateStrat1) {
		std::cout << "\nStrategy 2 is better than Strategy 1.\n";
	}
	else {
		std::cout << "\nStrategy 1 is better than Strategy 2.\n";
	}

}

//Main function, self explanatory. Starts seeding for use in rand() used to determine if a bullet hits or not (targetHit() function).
int main() {
	
	srand(time(0));
	std::cout << "*** Welcome to Hayden's Dual Simulator ***";
	testDrivers();
	strategyTests();

}
