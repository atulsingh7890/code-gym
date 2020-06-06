//// https://www.codechef.com/APRIL20B/problems/CARSELL
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main() {
//	int testcases = 0;
//	const int modulo_value = 1000000007;
//	std::cin >> testcases;
//	while (testcases--) {
//		int numbers = 0;
//		std::cin >> numbers;
//		std::vector<int> prices;
//		for (int i = 0; i < numbers; ++i) {
//			int temp;
//			std::cin >> temp;
//			prices.push_back(temp);
//		}
//		std::sort(prices.rbegin(), prices.rend());
//
//		long result = 0;
//		for (int i = 0; i < numbers; ++i) {
//			if(prices[i] - i >= 0 )
//				result = result + prices[i] - i;
//			else 
//				continue;
//
//			result %= modulo_value;
//		}
//
//		std::cout << result << std::endl;
//
//	}
//}