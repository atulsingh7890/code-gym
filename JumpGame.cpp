//#include <iostream>
//#include <vector>
//#include <map>
//#include <cassert>
//#include <algorithm>
//#include <time.h>
//#include <stdlib.h>
//#include <ctime>
//#include <chrono>
//
//class Solution {
//
//public:
//	std::chrono::microseconds method_0 ;
//	std::chrono::microseconds method_1 ;
//	std::chrono::microseconds method_2 ;
//	std::chrono::microseconds method_3;
//	long long outerloop_ran_method_1;
//	long long innerloop_ran_method_1;
//	long long outerloop_ran_method_3;
//	long long innerloop_ran_method_3;
//
//	Solution() {
//		method_0 = std::chrono::microseconds(0);
//		method_1 = std::chrono::microseconds(0);
//		method_2 = std::chrono::microseconds(0);
//		method_3 = std::chrono::microseconds(0);
//		outerloop_ran_method_1 = 0;
//		outerloop_ran_method_3 = 0;
//		innerloop_ran_method_1 = 0;
//		innerloop_ran_method_3 = 0;
//	}
//
//	bool areJumpsPossibleAnother(std::vector<int> &nums) {		
//		std::vector<bool> canJump(nums.size(), false);
//		// Can always jump to location 0
//		canJump[0] = true;
//
//		//loop over starting from the 2 nd element
//		for (int i = 1; i < nums.size(); ++i) {
//			// see if we can reach this point from any of previous points
//			for (int j = i - 1; j >= 0; --j) {
//				if (canJump[j] && nums[j] >= i - j) {
//					canJump[i] = true;
//					break;
//				}
//			}
//		}		
//		return canJump[nums.size() - 1] == true;
//	}
//
//	bool areJumpsPossible(std::vector<int> & nums) {		
//		std::vector<bool> is_reachable_to_end(nums.size(), false);
//		// last one is always reachable
//		is_reachable_to_end[nums.size() - 1] = true;
//		for (int i = nums.size() - 2; i >= 0; --i) {
//			outerloop_ran_method_1++;
//			int max_jump = std::min(i + nums[i], (int)nums.size() - 1);
//			for (int j = i + 1; j <= max_jump; ++j) {
//				// IF its reaching to end, then this is where we have to reach previous than last	
//				innerloop_ran_method_1++;
//				if (true == is_reachable_to_end[j]) {
//					is_reachable_to_end[i] = true;
//					break;
//				}
//			}
//		}
//
//		return is_reachable_to_end[0] == true;
//	}
//
//	bool areJumpsPossibleWithInt(std::vector<int> & nums) {
//		std::vector<int> is_reachable_to_end(nums.size(), 0);
//		// last one is always reachable
//		is_reachable_to_end[nums.size() - 1] = 1;
//		for (int i = nums.size() - 2; i >= 0; --i) {
//			outerloop_ran_method_3++;
//			int max_jump = std::min(i + nums[i], (int)nums.size() - 1);
//			for (int j = i + 1; j <= max_jump; ++j) {
//				innerloop_ran_method_3++;
//				// IF its reaching to end, then this is where we have to reach previous than last				
//				if (1 == is_reachable_to_end[j]) {
//					is_reachable_to_end[i] = 1;
//					break;
//				}
//			}
//		}
//
//		return is_reachable_to_end[0] == 1;
//	}
//
//	bool areJumpsPossibleNaive(std::vector<int> & nums, std::map<int, bool> cache, int start, int end) {
//		if (start == end) {
//			cache[start] = true;
//			return true;
//		}
//
//		if (start > end) {
//			return false;
//		}
//
//		bool result = false;
//		for (int i = 1; i <= nums[start]; ++i) {
//			if (cache[start + i]) {
//				result = true;
//				break;
//			}
//			if (areJumpsPossibleNaive(nums, cache, start + i, end)) {
//				result = true;
//				break;
//			}
//		}
//
//		cache[start] = result;
//		return result;
//	}
//
//	bool canJump(std::vector<int>& nums,  int method_choice) {
//
//		if (nums.size() == 0) {
//			return false;
//		}
//
//
//		if (method_choice == 0) {
//			std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//			std::map<int, bool> is_possible_to_reach_at_index;
//			bool result = areJumpsPossibleNaive(nums, is_possible_to_reach_at_index, 0, nums.size() - 1);
//			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//			
//			method_1 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//			return result;
//			
//
//		}
//		else if (method_choice == 1) {
//			std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//			bool result = areJumpsPossible(nums);
//			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//			method_1 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//			return result;
//		}
//		else if (method_choice == 2) {
//			std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//			
//			bool result = areJumpsPossibleAnother(nums);
//
//			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//			method_2 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//			return result;
//		}
//		else {
//			std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//			bool result = areJumpsPossibleWithInt(nums);
//
//			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//
//			method_3 += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//			return result;
//		}
//
//	}
//};
//
//
//
//int main() {
//	//{
//	//	std::vector<int> input{2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
//	//	Solution s;
//	//	bool answer = s.canJump(input,2);
//	//	assert(false == answer);
//	//}
//
//	//{
//	//	std::vector<int> input{ 1, 3, 2, 2, 0, 4 , 4, 4 };
//	//	Solution s;
//	//	bool answer = s.canJump(input, 2);
//	//	assert(true == answer);
//	//}
//
//	{
//		int n_testcases = 100;
//		int max_test_case_size = 100;
//		int max_size_of_each_number = 10;
//		Solution s;
//		for (int t = 0; t < n_testcases; ++t) {
//			srand(time(0));
//			int size_of_input = (rand() + 1) % max_test_case_size;
//			std::vector<int> input;
//			for (int i = 0; i < size_of_input; ++i) {
//				int current_value = (rand() + 1) % max_size_of_each_number;
//				input.push_back(current_value);
//			}			
//			bool answer_1 = s.canJump(input, 1);
//			bool answer_2 = s.canJump(input, 2);
//			bool answer_3 = s.canJump(input, 3);
//			assert(answer_1 == answer_2);
//			assert(answer_2 == answer_3);
//		}
//
//
//		std::cout << " Methods Taking Time : \n" << std::endl;
//		std::cout << "Method 0 took " << s.method_0.count() << " milliseconds" << std::endl;
//		std::cout << "Method 1 took " << s.method_1.count() << " milliseconds" << std::endl;
//		std::cout << "Method 2 took " << s.method_2.count() << " milliseconds" << std::endl;
//		std::cout << "Method 3 took " << s.method_3.count() << " milliseconds" << std::endl;
//
//		std::cout << "Method 1 and Method 3 Comparisons " << std::endl;
//		std::cout << "Outer Loop Ran : " << s.outerloop_ran_method_1 << " in Method 1 " << std::endl;
//		std::cout << "Outer Loop Ran : " << s.outerloop_ran_method_3 << " in Method 3 " << std::endl;
//
//
//		std::cout << "Inner Loop Ran : " << s.innerloop_ran_method_1 << " in Method 1 " << std::endl;
//		std::cout << "Inner Loop Ran : " << s.innerloop_ran_method_3 << " in Method 3 " << std::endl;
//	}
//
//
//}