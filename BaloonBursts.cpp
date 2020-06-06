////
////  BurstBaloons.cpp
////  CodeGym
////
////  Created by Atul Singh on 24/05/20.
////  Copyright © 2020 Atul Singh. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <limits>
//#include <cassert>
//#include <map>
//
//// [35,16,83,87,84,59,48,41,20,54]
//
//class Solution {
//
//	using VectorInts = std::vector<int>;
//	using VectorVectorInts = std::vector<VectorInts>;
//	using IntPair = std::pair<int, int>;
//	using VectorCache = std::map<std::vector<int>, int>;
//
//	int maxCoinsUseDP(VectorInts nums) {
//		if (nums.size() == 1) {
//			return nums[0];
//		}
//
//		VectorVectorInts dp(nums.size(), VectorInts(nums.size()));
//		for (int sequence_size = 0; sequence_size < nums.size(); ++sequence_size) {
//
//			// Iterate over a particular sequence size
//			for (int sequence_start = 0; sequence_start < nums.size() - sequence_size; ++sequence_start) {
//				int sequence_end = sequence_start + sequence_size;
//				for (int last_baloon_left_to_burst = sequence_start; last_baloon_left_to_burst <= sequence_end; last_baloon_left_to_burst++) {
//					
//					int previous_baloon_value = sequence_start > 0 ? nums[sequence_start - 1] : 1;
//					int next_baloon_value = sequence_end < nums.size() - 1 ? nums[sequence_end + 1] : 1;
//
//					int last_baloon_to_burst_answer = previous_baloon_value * nums[last_baloon_left_to_burst] * next_baloon_value;
//					int answer_collated_from_left_part = last_baloon_left_to_burst > sequence_start ? dp[sequence_start][last_baloon_left_to_burst - 1] : 0;
//					int answer_collated_from_right_part = last_baloon_left_to_burst < sequence_end ? dp[last_baloon_left_to_burst +1][sequence_end] : 0;
//
//					dp[sequence_start][sequence_end] = std::max(
//						dp[sequence_start][sequence_end],
//						answer_collated_from_left_part + last_baloon_to_burst_answer + answer_collated_from_right_part
//					);
//
//
//				}
//			}			
//		}
//		return dp[0][nums.size() - 1];
//		
//	}
//
//	int maxCoinsHelperVersionWithHeavyKeyCache(VectorInts nums, std::map<std::vector<int>, int> & cache) {
//		if (nums.size() == 1) {
//			return nums[0];
//		}
//
//		auto it = cache.find(nums);
//		if (it != cache.end())
//			return it->second;
//
//		int max_coins = std::numeric_limits<int>::min();
//		for (int i = 0; i < nums.size(); ++i) {
//			int preceding_number = i > 0 ? nums[i - 1] : 1;
//			int suceeding_number = i < nums.size() - 1 ? nums[i + 1] : 1;
//			int current_number = nums[i];
//
//			int current_result = preceding_number * current_number * suceeding_number;
//
//			if (i == 0) {
//				current_result += maxCoinsHelperVersionWithHeavyKeyCache(VectorInts(nums.begin() + 1, nums.end()), cache);
//			}
//			else if (i == nums.size() - 1) {
//				current_result += maxCoinsHelperVersionWithHeavyKeyCache(VectorInts(nums.begin(), nums.end() - 1), cache);
//			}
//			else {
//				VectorInts new_vector(nums.begin(), nums.begin() + i);
//				new_vector.insert(new_vector.end(), nums.begin() + i + 1, nums.end());
//				current_result += maxCoinsHelperVersionWithHeavyKeyCache(new_vector, cache);
//			}
//			max_coins = std::max(max_coins, current_result);
//		}
//
//		cache[nums] = max_coins;
//
//		return max_coins;
//	}
//
//	int maxCoinsHelperVersionZero(VectorInts nums) {
//		if (nums.size() == 1) {
//			return nums[0];
//		}
//		int max_coins = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			int preceding_number = i > 0 ? nums[i - 1] : 1;
//			int suceeding_number = i < nums.size() - 1 ? nums[i + 1] : 1;
//			int current_number = nums[i];
//
//			int current_result = preceding_number * current_number * suceeding_number;
//
//			if (i == 0) {
//				current_result += maxCoinsHelperVersionZero(VectorInts(nums.begin() + 1, nums.end()));
//			}
//			else if (i == nums.size() - 1) {
//				current_result += maxCoinsHelperVersionZero(VectorInts(nums.begin(), nums.end() - 1));
//			}
//			else {
//				VectorInts new_vector(nums.begin(), nums.begin() + i);
//				new_vector.insert(new_vector.end(), nums.begin() + i + 1, nums.end());
//				current_result += maxCoinsHelperVersionZero(new_vector);
//			}
//			max_coins = std::max(max_coins, current_result);
//		}
//
//		return max_coins;
//	}
//
//public:
//	int maxCoins(std::vector<int> nums) {
//		if (nums.size() == 0) {
//			return 0;
//		}
//
//		//return maxCoinsHelperVersionZero(nums);
//
//		return maxCoinsUseDP(nums);
//
//	}
//};
//
//
//int main() {
//	{
//		Solution s;
//		std::vector<int> input_array{};
//		int aswer = s.maxCoins(input_array);
//		assert(aswer == 0);
//	}
//	{
//		Solution s;
//		std::vector<int> input_array{ 3,1,5,8 };
//		int aswer = s.maxCoins(input_array);
//		assert(aswer == 167);
//	}
//
//	{
//		Solution s;
//		std::vector<int> input_array{ 35,16,83,87,84,59,48,41,20,54 };
//		int aswer = s.maxCoins(input_array);
//		assert(aswer == 1849648);
//	}
//
//	{
//		Solution s;
//		std::vector<int> input_array{ 3, 5, 8 };
//		int aswer = s.maxCoins(input_array);
//		assert(aswer == 152);
//	}
//
//	{
//		Solution s;
//		std::vector<int> input_array{ 8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2 };
//		int aswer = s.maxCoins(input_array);
//		assert(aswer == 3414);
//	}
//
//}
