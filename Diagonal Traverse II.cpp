//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//class Solution {
//public:
//	int max_(int a, int b) {
//		return a > b ? a : b;
//	}
//	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//		vector<int> final_result;
//
//		int rows = nums.size();
//		int cols = 0;
//
//		for (int i = 0; i < nums.size(); ++i) {
//			cols = max_(cols, nums[i].size());
//		}
//
//		int max_dimension = std::max(rows, cols);
//
//
//
//		for (int i = 0; i < max_dimension; ++i) {
//			int cur_row = i, cur_col = 0;
//			while (cur_row >= 0) {
//				if (cur_row >= 0 && cur_row < nums.size() && cur_col >= 0 && cur_col < nums[cur_row].size()) {
//					final_result.push_back(nums[cur_row][cur_col]);
//				}
//				cur_row--, cur_col++;
//			}
//		}
//
//		for (int i = 1; i < max_dimension; ++i) {
//			int cur_col = i, cur_row = max_dimension - 1;
//			while (cur_col < max_dimension) {
//				if (cur_row >= 0 && cur_row < nums.size() && cur_col >= 0 && cur_col < nums[cur_row].size()) {
//					final_result.push_back(nums[cur_row][cur_col]);
//				}
//				cur_row--, cur_col++;
//			}
//		}
//
//		return final_result;
//
//	}
//};
//
//
//int main() {
//
//	std::vector<std::vector<int>> input = { {1}, {4}, {5} };
//
//	Solution s;
//	std::vector<int> result = s.findDiagonalOrder(input);
//	for (int i = 0; i < result.size(); ++i) {
//		std::cout << result[i] << " ";
//	}
//}