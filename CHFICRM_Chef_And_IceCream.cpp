////https://www.codechef.com/JUNE20B/problems/CHFICRM
//
//#include <iostream>
//#include <array>
//
//int main() {
//	int testcases = 0;
//	std::cin >> testcases;
//	while (testcases--) {
//		int N = 0;
//		std::cin >> N;
//		std::array<int, 2> change_count({ 0,0 });		
//
//		bool answer = true;
//		while (N--) {
//			int a = 0;
//			std::cin >> a;
//			if (answer) {
//				switch (a)
//				{
//				case 5:
//				{
//					change_count[0]++;
//				}
//				break;
//				case 10:
//				{
//					if (change_count[0] > 0) {
//						change_count[0]--;
//						change_count[1]++;
//					}
//					else {
//						answer = false;
//					}
//				}
//				break;
//				case 15:
//				{
//					if (change_count[1] > 0) {
//						change_count[1]--;
//					}
//					else if (change_count[0] > 1) {
//						change_count[0]--;
//						change_count[0]--;
//					}
//					else {
//						answer = false;
//					}
//				}
//				}
//			}			
//						
//		}
//		answer ? std::cout << "YES\n" : std::cout << "NO\n";
//	}
//}