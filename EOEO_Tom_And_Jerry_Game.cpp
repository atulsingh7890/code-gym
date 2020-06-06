//https://www.codechef.com/JUNE20B/problems/EOEO

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

bool play_game(int TS, int JS) {
	if (((TS & 0x1) == 1) && ((JS & 0x1) == 1))
		return false;
	if (((TS & 0x1) == 1) && ((JS & 0x1) == 0))
		return true;
	if (((TS & 0x1) == 0) && ((JS & 0x1) == 1))
		return false;
	if (((TS & 0x1) == 0) && ((JS & 0x1) == 0))
		return play_game(TS / 2, JS / 2);
}

int brute_force(int TS) {
	int result = 0;
	for (int i = 1; i <= TS; ++i) {
		result += play_game(TS, i);
	}
	return result;
}

long long efficient(long long TS) {
	long long answer = 0;
	if ((TS % 2) == 1)
		answer =  TS / 2;
	else {
		while ((TS) % 2 != 1) {
			TS = TS / 2;
		}
		answer = TS / 2;
	}
	return answer;
}

int main() {
	int testcases = 0;
	std::cin >> testcases;
	//std::srand(std::time(nullptr));
	while (testcases--) {
		long long TS = 0;
		std::cin >> TS;
		//TS = std::rand() % 100;
		//int result_bf = brute_force(TS);		
		long long result_eff = efficient(TS);
		//assert(result_bf == result_eff);
		std::cout << result_eff << std::endl;
	}
}