//#include <vector>
//#include <algorithm>
//
//class Solution {
//
//	//enum DirectionToGo {
//	//	UP = 0,
//	//	DOWN
//	//};
//
//	/*int movesToMakeZigZag(const std::vector<int>& nums, int current_index,int previous_element, DirectionToGo direction) {
//		if (current_index == nums.size() - 1) {
//			if (direction == UP) {
//				return nums[current_index] > previous_element ? 0 : previous_element - nums[current_index] + 1;
//			}
//			else {
//				return nums[current_index] < previous_element ? 0 : nums[current_index] - previous_element + 1;
//			}
//		}
//
//		int current_element = nums[current_index];
//		int moves_for_up = 0;
//		int moves_for_down = 0;
//		if (direction == UP) {
//			if (current_element <= previous_element) {
//				moves_for_up = previous_element - current_element + 1;
//			}
//			moves_for_up += movesToMakeZigZag(nums, current_index + 1, current_element + moves_for_up, DOWN);
//			return moves_for_up;
//		}
//		else {
//			if (current_element >= previous_element) {
//				moves_for_down = current_element - previous_element+ 1;
//			}
//			moves_for_down += movesToMakeZigZag(nums, current_index + 1, current_element - moves_for_down, UP);
//			return moves_for_down;
//		}		
//		
//	}*/
//
//	int makePeak(const std::vector<int>& nums, int current_index) {
//		if (current_index >= nums.size()) {
//			return 0;
//		}
//
//		int left_value = current_index == 0 ? nums[current_index] - 1 : nums[current_index - 1];
//		int right_value = current_index == nums.size() - 1 ? nums[current_index] - 1 : nums[current_index + 1];
//		int moves = std::max(left_value, right_value) - nums[current_index]  +  1;
//
//		return std::max(moves, 0) + makePeak(nums, current_index + 2);
//	}
//
//public:
//	int movesToMakeZigzag(const std::vector<int>& nums) {
//
//		if (nums.size() == 0) {
//			return 0;
//		}
//
//		return std::min(makePeak(nums, 0), makePeak(nums, 1));
//
//	}
//};
//
//int main() {
//	Solution s;
//	s.movesToMakeZigzag({10, 4, 4, 10, 10, 6, 2, 3});
//}