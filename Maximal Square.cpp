////
////  MaximalSqaure.cpp
////  CodeGym
////
////  Created by Atul Singh on 27/04/20.
////  Copyright © 2020 Atul Singh. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <memory>
//#include <map>
//#include <cassert>
//
//
//class Solution {
//public:
//	using Matrix = std::vector<std::vector<int>>;
//
//	int countSquares(Matrix & matrix) {
//
//		if (matrix.size() == 0) {
//			return 0;
//		}
//
//		Matrix aux_matrix(matrix.size());
//		for (int i = 0; i < aux_matrix.size(); ++i) {
//			aux_matrix[i].resize(matrix[0].size());
//		}
//
//		int total_squares = 0;
//		int size_one_side_of_square = 0;
//		for (int i = 0; i < matrix.size(); ++i) {
//			for (int j = 0; j < matrix[i].size(); ++j) {
//				if (matrix[i][j] == 1) {
//					size_one_side_of_square++;					
//				}
//			}
//		}
//
//		if (size_one_side_of_square == 0) {
//			return 0;
//		}
//
//		total_squares += size_one_side_of_square;
//
//
//		Matrix *data_matrix, *square_info;
//		data_matrix = &matrix;
//		square_info = &aux_matrix;
//
//		int start_row = 0, end_row = matrix.size() - 1;
//		int start_col = 0, end_col = matrix[0].size() - 1;
//		bool square_found = true;
//		while (square_found && start_row < end_row && start_col < end_col) {
//
//			square_found = false;
//			int squares_found = 0;
//			for (int i = start_row + 1; i <= end_row; ++i) {
//				for (int j = start_col + 1; j <= end_col; ++j) {
//					const int & north_value = (*data_matrix)[i - 1][j];
//					const int & west_value = (*data_matrix)[i][j - 1];
//					const int & north_west_value = (*data_matrix)[i - 1][j - 1];
//					const int & current_value = (*data_matrix)[i][j];
//
//					if (current_value == 1
//						&& north_value == 1
//						&& west_value == 1
//						&& north_west_value == 1) {
//
//						square_found = true;
//						squares_found++;
//
//						(*square_info)[i][j] = 1;
//					}
//					else {
//						(*square_info)[i][j] = 0;
//					}
//				}
//			}
//			std::swap(square_info, data_matrix);
//			start_row++, start_col++;	
//			total_squares += squares_found;
//		}
//
//		return total_squares;
//	}
//};
//
//
//int main() {
//
//	std::map<Solution::Matrix, int> testcases{
//	{{{}}, 0 },
//	{{{1}}, 1},
//	{{
//	  {1, 1},
//	  {1, 1}
//	  },
//		5},
//	{{
//	  {0, 1, 1},
//	  {1, 1, 1},
//	  {0, 1, 0},
//	  },
//		7},
//	{{
//	  {1, 1, 1},
//	  {1, 1, 1},
//	  {1, 1, 1},
//	  },
//		14},
//	{{
//	  {0, 1, 1, 1},
//	  {1, 1, 1, 1},
//	  {0, 1, 1, 1},
//	  },
//		15},
//	/*{{
//	  {0, 1, 1},
//	  {1, 1, 1},
//	  {1, 1, 1},
//	  },
//		4},
//	{{
//	  {0, 1, 1},
//	  {1, 1, 1},
//	  {1, 1, 0},
//	  },
//		4},
//	{{
//	  {0, 1, 0},
//	  {1, 1, 1},
//	  {0, 1, 0},
//	  },
//		1},*/
//	};
//
//	for (auto &testcase : testcases) {
//		Solution s;
//		Solution::Matrix m = testcase.first;
//		int answer = s.countSquares(m);
//		assert(answer == testcase.second);
//	}
//
//}
