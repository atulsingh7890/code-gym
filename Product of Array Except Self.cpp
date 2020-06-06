//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cassert>
//
//class Solution {
//public:
//	std::vector<int> productExceptSelf(std::vector<int>& nums) {
//
//		std::vector<int> output(nums.begin(), nums.end());
//		
//		int previous_multiplier = 1;
//		for (auto & number : nums) {
//			int  current_num = number;			
//			number = previous_multiplier;
//			previous_multiplier *= current_num;			
//		}
//
//		previous_multiplier = 1;
//
//		for (int i = output.size() - 1; i >= 0; --i) {
//			int current_num = output[i];
//			output[i] = previous_multiplier * nums[i];
//			previous_multiplier *= current_num;
//		}
//
//		return output;
//	}
//};
//
//int main() {
//
//	{
//		std::vector<int> input_array{ 1,2,3,4 };
//		Solution s;
//		std::vector<int> ouput_array = s.productExceptSelf(input_array);
//		assert(std::equal(ouput_array.begin(), ouput_array.end(),
//			std::vector<int>({24, 12, 8, 6}).begin()));		
//	}
//
//	{
//		std::vector<int> input_array{ 2,2,3,4 };
//		Solution s;
//		std::vector<int> ouput_array = s.productExceptSelf(input_array);
//		assert(std::equal(ouput_array.begin(), ouput_array.end(),
//			std::vector<int>({ 24, 24, 16, 12 }).begin()));
//	}
//
//
//	{
//		std::vector<int> input_array{ 1,2 };
//		Solution s;
//		std::vector<int> ouput_array = s.productExceptSelf(input_array);
//		assert(std::equal(ouput_array.begin(), ouput_array.end(),
//			std::vector<int>({ 2, 1 }).begin()));
//	}
//
//}