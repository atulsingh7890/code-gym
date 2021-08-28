//https://www.codechef.com/problems/RECTANGL
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	int testcases = 0;
	std::cin >> testcases;
	
	while(testcases--)
	{
	    std::array<int, 4> sides;
	    std::cin >> sides[0] >> sides[1] >> sides[2] >> sides[3];
	    std::sort(sides.begin(), sides.end());
	    if(sides[0] != 0 && sides[0] == sides[1] && sides[2] == sides[3]) {
	        std::cout << "YES\n";
	    } else {
	        std::cout << "NO\n";
	    }
	}
	return 0;
}
