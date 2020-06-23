//// https://www.codechef.com/JUNE20B/problems/EVENM
//
//#include <iostream>
//#include <vector>
//
//int main() {
//	int testcases = 0;
//	std::cin >> testcases;
//	while (testcases--) {
//		int N = 0;
//		std::cin >> N;
//		int start_element = 1;
//
//		// 		if (N == 1) {
//		// 			std::cout << "0" << std::endl;
//		// 		    continue;
//		// 		}
//
//		std::vector<std::vector<int>> delicious_matrix(N, std::vector<int>(N, 0));
//
//		int current_element = 1;
//		for (int i = 0; i < N; ++i) {
//			int current_row_start = 0;
//			int current_row_end = N - 1;
//			int step = 1;
//			if (i & 0x01) {
//				// if row is Odd, start from backwards otherwise from front
//				current_row_start = current_row_end;
//				current_row_end = 0;
//				step = -1;
//			}
//			for (int j = current_row_start; step > 0 ? j <= current_row_end : j >= current_row_end; j += step) {
//				delicious_matrix[i][j] = current_element++;
//			}
//		}
//
//		for (int i = 0; i < N; ++i) {
//			for (int j = 0; j < N; ++j) {
//				std::cout << delicious_matrix[i][j] << " ";
//			}
//			std::cout << "\n";
//		}
//	}
//}