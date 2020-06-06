//#include <vector>
//#include <cassert>
//class Solution {
//public:
//	int singleNonDuplicate(std::vector<int>& nums) {
//		int start = 0, end = nums.size() - 1;
//		while (start < end) {
//
//			int mid = end - (end - start) / 2;
//
//			if (end - start == 2) {
//				return nums[end] != nums[mid] ? nums[end] : nums[start];
//			}
//
//			if (((start+mid) & 0x1) && nums[mid] == nums[mid - 1]) {
//				start = mid+1;
//			}
//			else if (((start + mid) & 0x1) && nums[mid] != nums[mid - 1]) {
//				end = mid-1;
//			}		
//			else if (nums[mid] == nums[mid + 1]) {
//				start = mid;
//			}
//			else {
//				end = mid;
//			}
//
//		}
//
//		return nums[0];
//	}
//};
//
//int main() {
//
//	{
//		std::vector<int> input_vector = { 3, 3, 7, 7, 10, 10, 11, 12, 12 };
//		Solution s;
//		assert(11 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = { 3, 3, 7, 10, 10, 11, 11 };
//		Solution s;
//		assert(7 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = { 3, 3, 7, 7, 10, 11, 11 };
//		Solution s;
//		assert(10 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = { 1, 2, 2, 3, 3 };
//		Solution s;
//		assert(1 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = { 1, 2, 2 };
//		Solution s;
//		assert(1 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = { 1, 1, 2 };
//		Solution s;
//		assert(2 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = { 1, 1, 2 };
//		Solution s;
//		assert(2 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = {1, 1, 2, 3, 3, 4, 4, 8, 8};
//		Solution s;
//		assert(2 == s.singleNonDuplicate(input_vector));
//	}
//	{
//		std::vector<int> input_vector = { 1, 1, 2, 2,3, 3, 4, 4, 8, 8, 9 };
//		Solution s;
//		assert(9 == s.singleNonDuplicate(input_vector));
//	}
//}