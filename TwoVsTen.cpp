//https://www.codechef.com/problems/TWOVSTEN
#include <iostream>
using namespace std;

int main() {
	
	int testcases = 0;
	std::cin >> testcases;
	while(testcases--) {
	    int N;
	    std::cin >> N;
	    int steps = 0;
	    if(N % 10 == 0)
	    	steps = 0;
	    else if(N % 5 == 0 )
	    	steps = 1;
	    else
	    	steps = -1;
	    
	    std::cout << steps << "\n";
	}
	
	return 0;
}
