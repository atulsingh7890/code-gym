////
////  UncrossedLines.cpp
////  CodeGym
////
////  Created by Atul Singh on 25/05/20.
////  Copyright © 2020 Atul Singh. All rights reserved.
////
//
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <cassert>
//
//class Solution {
//public:
//
//	int maxUncrossedLinesDP(const std::vector<int>& A, const std::vector<int>& B) {
//		if (A.size() == 0 || B.size() == 0) {
//			return 0;
//		}
//
//		std::vector<std::vector<int>> dp(A.size(), std::vector<int>(B.size()));
//
//		for (int start_a = 0; start_a < A.size(); ++start_a) {
//			for (int start_b = 0; start_b < B.size(); ++start_b) {
//				
//				int north_value = start_a > 0 ? dp[start_a - 1][start_b] : 0;
//				int west_value = start_b > 0 ? dp[start_a][start_b - 1] : 0;
//				int north_west_value = start_a > 0 && start_b > 0 ? dp[start_a - 1][start_b - 1] : 0;
//
//				if (A[start_a] == B[start_b]) {
//					dp[start_a][start_b] = 1 + north_west_value;
//				}
//				else {
//					dp[start_a][start_b] = std::max(north_value, west_value);
//				}
//
//			}
//		}
//
//		return dp[A.size() - 1][B.size() - 1];
//	}
//
//	int maxUncrossedLines(const std::vector<int>& A, const std::vector<int>& B, int start_a, int start_b) {
//
//		return maxUncrossedLinesDP(A, B);
//
//
//		//if (A.size() == start_a || B.size() == start_b) {
//		//	return 0;
//		//}
//
//		//int uncrossed_lines = 0;
//		//// if Both are equal lets make the line
//		//if (A[start_a] == B[start_b]) {
//		//	uncrossed_lines =  1 + maxUncrossedLines(A, B, start_a + 1, start_b + 1);
//		//} else {
//		//	uncrossed_lines =  std::max(
//		//		maxUncrossedLines(A, B, start_a + 1, start_b),
//		//		maxUncrossedLines(A, B, start_a, start_b + 1)
//		//	);
//		//}
//
//		//return uncrossed_lines;
//	}
//
//
//};
//
//int main() {
//	std::map<std::pair<std::vector<int>, std::vector<int>>, int>  testcases{
//		{ 
//			{
//				{2, 5, 1, 2, 5},
//				{10, 5, 2, 1, 5, 2}
//			}
//			,3
//		},
//		{
//			{
//				{1, 3, 7, 1, 7, 5},
//				{1, 9, 2, 5, 1}
//			}
//			,2
//		},
//		{
//			{
//				{3, 2},
//				{2, 2, 2, 3}
//			}
//			,1
//		},
//	};
//
//	for (auto & testcase : testcases) {
//		Solution s;
//		int answer = s.maxUncrossedLines(testcase.first.first, testcase.first.second, 0, 0);
//		assert(answer == testcase.second);
//	}
//}