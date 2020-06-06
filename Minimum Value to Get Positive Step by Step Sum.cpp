//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//	int minStartValue(vector<int>& nums) {
//		int start_value = nums[0] > 0 ? 1 : -nums[0] + 1;
//		int previous_sum = start_value;
//		for (auto n : nums) {
//			int current_value = previous_sum + n;
//			int increment_in_start_value = 0;
//			if (current_value < 1) {
//				increment_in_start_value = 1 - current_value;
//				start_value += increment_in_start_value;
//			}
//			previous_sum = previous_sum + n + increment_in_start_value;
//		}
//		return start_value;
//	}
//};
//
//int main() {
//
//	std::vector<int> input_vector = { 1, -2, -3 };
//	Solution s;
//	std::cout << s.minStartValue(input_vector);
//}