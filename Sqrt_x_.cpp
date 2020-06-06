//#include <iostream>
//
//class Solution {
//public:
//	int mySqrt(int x) {
//		int start = 1;
//		int end = x >> 1;
//
//		while (start <= end) {
//			int mid = start + ((end - start) >> 1);
//			int current_multiplication = mid * mid;
//			if (current_multiplication == x)
//				return mid;
//			if (current_multiplication < x)
//				start = mid + 1;
//			else
//				end = mid - 1;
//		}
//		return -1;
//		
//	}
//};
//
//
//int main()
//{
//
//	Solution s;
//	std::cout << s.mySqrt(8);
//}