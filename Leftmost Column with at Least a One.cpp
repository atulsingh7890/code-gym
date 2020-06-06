//#include <iostream>
//#include <vector>
//#include <limits>
//#include <algorithm>
//
///**
// * // This is the BinaryMatrix's API interface.
// * // You should not implement it, or speculate about its implementation
// * class BinaryMatrix {
// *   public:
// *     int get(int x, int y);
// *     vector<int> dimensions();
// * };
// */
//
//class Solution {
//public:
//
//	int leftMostColumnWithOne(std::vector<std::vector<bool>> &binaryMatrix) {
//		const int rows = binaryMatrix.size();
//		const int cols = binaryMatrix[0].size();
//
//		int r = 0, c = cols - 1;
//		
//		auto isValid = [&](int r, int c) {return r >= 0 && r < rows && c >= 0 && c < cols;  };
//
//		int result = -1;
//
//		while (isValid(r, c)) {
//			binaryMatrix[r][c] ? result = c-- : r++;
//		}
//				
//		return result;
//	}
//
//	////int leftMostColumnWithOne(std::vector<std::vector<bool>> &binaryMatrix) {
//	////	int rows = binaryMatrix.size();
//	////	int cols = binaryMatrix[0].size();
//
//	////	int first_column_with_atleast_one = std::numeric_limits<int>::max();
//
//	////	for (int i = 0; i < rows; ++i) {			
//	////		// Find the Index of 1 in here
//	////		int s = 0;
//	////		int e = cols - 1;
//	////		int first_true_index = first_column_with_atleast_one;
//
//	////		if (binaryMatrix[i][0] == true) {
//	////			first_column_with_atleast_one = 0;
//	////			break;
//	////		}
//
//	////		if (first_column_with_atleast_one != std::numeric_limits<int>::max() && first_column_with_atleast_one >= s && first_column_with_atleast_one <= e) {
//	////			if (binaryMatrix[i][first_column_with_atleast_one] == 0) {
//	////				// There is no point of searching in here, as its already 0 here
//	////				continue;
//	////			}
//	////		}		
//
//	////		while (s <= e) {
//	////			int mid = (s + e) / 2;
//	////			if (mid > s && (binaryMatrix[i][mid - 1] == false) && (binaryMatrix[i][mid] == true)) {
//	////				first_true_index = mid;  break;
//	////			}					
//	////			else if (mid < e && (binaryMatrix[i][mid + 1] == true) && (binaryMatrix[i][mid] == false)) {
//	////				first_true_index = mid + 1; break;
//	////			}					
//	////			else if (binaryMatrix[i][mid] == false) {
//	////				s = mid + 1;
//	////			}
//	////			else {
//	////				e = mid - 1;
//	////			}
//	////		}
//	////		first_column_with_atleast_one = std::min(first_column_with_atleast_one, first_true_index);
//	////	}
//	////	return first_column_with_atleast_one != std::numeric_limits<int>::max() ? first_column_with_atleast_one : -1;
//	////}
//};
//
//
//int main() {
//	{
//		Solution s;
//		std::vector<std::vector<bool>> input_matrix = { 
//			{0, 0},
//			{0, 0} };
//
//		std::cout << s.leftMostColumnWithOne(input_matrix) << std::endl;
//	}
//
//	{
//		Solution s;
//		std::vector<std::vector<bool>> input_matrix = {
//			{0, 1},
//			{0, 0} };
//
//		std::cout << s.leftMostColumnWithOne(input_matrix) << std::endl;
//	}
//
//
//	{
//		Solution s;
//		std::vector<std::vector<bool>> input_matrix = {
//			{1, 1},
//			{0, 0} };
//
//		std::cout << s.leftMostColumnWithOne(input_matrix) << std::endl;
//	}
//
//	{
//		Solution s;
//		std::vector<std::vector<bool>> input_matrix = {
//			{0, 1, 1, 1},
//			{0, 0, 1, 1} };
//
//		std::cout << s.leftMostColumnWithOne(input_matrix) << std::endl;
//	}
//
//	{
//		Solution s;
//		std::vector<std::vector<bool>> input_matrix = {
//			{0, 0, 0, 0, 1, 1, 1, 1, 1},
//			{0, 0, 0, 0, 0, 1, 1, 1, 1},
//			{0, 0, 0, 0, 1, 1, 1, 1, 1},
//			{0, 0, 0, 0, 0, 0, 1, 1, 1},
//			{0, 0, 0, 0, 0, 0, 0, 1, 1},
//			{0, 0, 0, 1, 1, 1, 1, 1, 1},
//			{0, 0, 0, 0, 1, 1, 1, 1, 1},
//			{0, 0, 0, 0, 1, 1, 1, 1, 1},
//			{0, 0, 0, 0, 0, 0, 0, 0, 1}};
//
//		std::cout << s.leftMostColumnWithOne(input_matrix) << std::endl;
//	}
//}