//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cassert>
//
//class Solution {
//public:
//	std::string stringShift(std::string s, std::vector<std::vector<int>>& shift) {
//		int total_left_rotations = 0;		
//		int total_right_rotations = 0;		
//		for (auto &shifts : shift) {
//			switch (shifts[0]) {
//			case 0:
//				total_left_rotations += shifts[1];
//				break;
//			case 1 : 
//				total_right_rotations += shifts[1];
//			}
//		}
//		
//		total_left_rotations = total_left_rotations % s.size();
//		total_right_rotations = total_right_rotations % s.size();
//
//		std::rotate(s.begin(), s.begin() + total_left_rotations, s.end());
//		std::rotate(s.rbegin(), s.rbegin() + total_right_rotations, s.rend());
//		
//		return s;
//
//	}
//
//	std::string stringShiftBruteForce(std::string s, std::vector<std::vector<int>>& shift) {
//		int shifts = 0;
//
//		for (int i = 0; i < shift.size(); ++i) {			
//			switch (shift[i][0]) {
//			case 0:
//			{	
//				shifts = shift[i][1] % s.size();
//				std::rotate(s.begin(), s.begin() + shifts, s.end());
//			}
//			break;
//			case 1:
//			{
//				shifts = shift[i][1] % s.size();				
//				std::rotate(s.rbegin(), s.rbegin() + shifts, s.rend());
//			}
//			break;
//
//			}
//		}
//		return s;
//	}
//};
//
//
//
//int main() {
//	{
//		std::string input_string = "abc";
//		std::vector<std::vector<int>> directions = { {0,1}, {1,2} };
//		Solution s;
//		std::string brute_force_answer = s.stringShiftBruteForce(input_string, directions);
//		std::string actual_answer = s.stringShift(input_string, directions);
//		assert(actual_answer == brute_force_answer);
//		std::cout << s.stringShiftBruteForce(input_string, directions) << std::endl;
//	}
//
//	{
//		std::string input_string = "abcdefg";
//		std::vector<std::vector<int>> directions = { {1,1}, {1,1}, {0,2}, {1,3} };
//		Solution s;
//		std::string brute_force_answer = s.stringShiftBruteForce(input_string, directions);
//		std::string actual_answer = s.stringShift(input_string, directions);
//		assert(actual_answer == brute_force_answer);
//		std::cout << s.stringShiftBruteForce(input_string, directions) << std::endl;
//	}
//}