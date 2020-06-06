//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <array>
//#include <algorithm>
//
//int main() {
//	int testcases = 0;
//	scanf_s("%d", &testcases);
//
//	while (testcases--) {
//		int N, Q;
//		scanf_s("%d %d", &N, &Q);
//
//		std::string str;
//		std::cin >> str;
//
//		std::array<int, 26> people_infected;
//		std::fill(people_infected.begin(), people_infected.end(), 0);
//
//		for (int i = 0; i < str.length(); ++i) {
//			people_infected[str[i] - 'a'] += 1;
//		}
//
//		while (Q--) {
//			int isolation_centers = 0;
//			scanf_s("%d", &isolation_centers);
//			int people_in_queue = 0;
//			for (int i = 0; i < 26; ++i) {
//				int people_after_putting_in_isoloation_centers = people_infected[i] - isolation_centers;
//				
//				people_in_queue += people_after_putting_in_isoloation_centers >= 0
//					? people_after_putting_in_isoloation_centers
//					: 0;
//			}
//
//			printf("%d\n", people_in_queue);
//		}
//	}
//}