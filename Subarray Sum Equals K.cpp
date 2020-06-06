//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <cassert>
//
//class Solution {
//public:
//
//	int subarraySum(std::vector<int>& nums, int k) {
//		auto length_array = nums.size();
//
//		std::unordered_map<int, int> rightSum;
//		int current_right_sum = 0;
//
//		int result = 0;
//		auto count_result = [&](int & sum) -> void { (sum == k) ? result++ : result; };
//
//		for (auto n : nums) {
//			current_right_sum += n;			
//			count_result(current_right_sum);
//
//			if (rightSum.find(current_right_sum - k) != rightSum.end()) {
//				result += rightSum[current_right_sum - k];
//			}
//
//			rightSum[current_right_sum]++;
//		}
//		return result;
//	}
//
//	int subarraySumDP(std::vector<int>& nums, int k) {
//		auto length_array = nums.size();
//		std::vector<std::vector<int>> segments(length_array);
//		for (int i = 0; i < length_array; ++i) {
//			segments[i].resize(length_array);
//		}
//
//		int result = 0;
//		auto count_result = [&](int & sum) -> void { (sum == k) ? result++ : result; };
//
//		for (int i = 0; i < length_array; ++i) {
//			for (int j = i; j < length_array; ++j) {
//				if (i == j) {
//					segments[i][j] = nums[i];
//				}
//				else {
//					segments[i][j] = nums[j] + segments[i][j - 1];
//				}
//				count_result(segments[i][j]);
//			}
//		}
//
//		return result;
//	}
//
//
//	int subarraySumDPWithIndicesSum(std::vector<int>& nums, int k) {
//		auto length_array = nums.size();
//		std::vector<int> sum_upto_index(length_array+1);
//
//		int result = 0;
//		auto count_result = [&](const int & sum) -> void { (sum == k) ? result++ : result; };
//
//		sum_upto_index[0] = 0;
//		for (int i = 1; i <= length_array; ++i) {
//			sum_upto_index[i] = sum_upto_index[i-1] + nums[i-1];			
//		}
//
//		for (int i = 0; i < length_array; ++i) {
//			for (int j = i+1; j <= length_array; ++j) {
//				// Count if sum[0...i]  - sum[0.....j]  i.e  sum(i,j) == k
//				count_result(sum_upto_index[j] - sum_upto_index[i]);
//			}
//		}
//
//		return result;
//	}
//};
//
//int main() {
//	{
//		std::vector<int> input_array{ 1 };
//		Solution s;
//		int sum_to_find = 0;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//	{
//		std::vector<int> input_array{ 10, 2, -2, -20, 10 };
//		Solution s;
//		int sum_to_find = 10;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//	{
//		std::vector<int> input_array{ 1, 1, 1 };
//		Solution s;
//		int sum_to_find = 2;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//
//	{
//		std::vector<int> input_array{ 1, 1, 1 };
//		Solution s;
//		int sum_to_find = 0;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//
//	{
//		std::vector<int> input_array{ 1, 1, 1 };
//		Solution s;
//		int sum_to_find = 3;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//
//	{
//		std::vector<int> input_array{ 1, 1, 2, 1, 1 };
//		Solution s;
//		int sum_to_find = 3;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//
//	{
//		std::vector<int> input_array{ 1, 1, 2, 1, 1 };
//		Solution s;
//		int sum_to_find = 1;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//
//	{
//		std::vector<int> input_array{ 1, 1, 2, 1, 1 };
//		Solution s;
//		int sum_to_find = 2;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//
//	{
//		std::vector<int> input_array{ 10, 2, -2, -20, 10 };
//		Solution s;
//		int sum_to_find = -10;
//		int answer_a = s.subarraySumDPWithIndicesSum(input_array, sum_to_find);
//		int answer_b = s.subarraySumDP(input_array, sum_to_find);
//		assert(answer_a == answer_b);
//		std::cout << s.subarraySumDPWithIndicesSum(input_array, sum_to_find) << std::endl;
//	}
//}