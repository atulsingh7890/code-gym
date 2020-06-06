////
////  MaximumSubarrayInCircularArray.cpp
////  CodeGym
////
////  Created by Atul Singh on 15/05/20.
////  Copyright © 2020 Atul Singh. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <map>
//#include <cassert>
//#include <algorithm>
//
//class Solution {
//public:
//    int maxSubarraySumCircularOld(std::vector<int>& a) {
//        int max_sub_array_sum_within_bounaries = maximumSubarraySumKadane(a);
//        
//        int max_sum_possible_wrapping_boundaries = 0;
//        for (int i = 0; i < a.size(); i++)
//        {
//                max_sum_possible_wrapping_boundaries += a[i]; // Calculate array-sum
//                a[i] = -a[i]; // invert the array (change sign)
//        }
//        
//        int mini_sub_array_with_negative_sum = maximumSubarraySumKadane(a);
//        
//        // Subtract the minimum possible subarray sum of, within the boundary
//        max_sum_possible_wrapping_boundaries = max_sum_possible_wrapping_boundaries + mini_sub_array_with_negative_sum;
//        
//        if(0 != max_sum_possible_wrapping_boundaries) {
//            // This means all the numbers were not negative and now the sum is not coming 0, return the original answer
//            max_sub_array_sum_within_bounaries = std::max(max_sub_array_sum_within_bounaries, max_sum_possible_wrapping_boundaries);
//        }
//        
//        return max_sub_array_sum_within_bounaries;
//    }
//
//	int maxSubarraySumCircular(const std::vector<int>& a) {
//		int max_subarray_sum = maximumSubarraySumKadane(a);
//		if (max_subarray_sum >= 0) {
//			// We do contain  some positives , lets dig more
//			std::vector<int> max_so_far_from_left = maxSumDataFromStart(std::vector<int>(a.begin(), a.end()));
//			std::vector<int> max_so_far_from_right = maxSumDataFromStart(std::vector<int>(a.rbegin(), a.rend()));
//
//			std::reverse(max_so_far_from_right.begin(), max_so_far_from_right.end());
//
//
//			int max_sum = std::numeric_limits<int>::min();
//			for (int i = 0; i < a.size() - 1; ++i) {
//				max_sum = std::max(max_sum, max_so_far_from_left[i] + max_so_far_from_right[i + 1]);
//			}
//
//			max_subarray_sum = std::max(max_subarray_sum, max_sum);
//		}
//
//		return max_subarray_sum;
//	}
//
//private:
//	int maximumSubarraySumKadane(const std::vector<int>& a) {
//
//		int max_so_far = std::numeric_limits<int>::min(), max_ending_here = 0;
//
//		for (int i = 0; i < a.size(); i++)
//		{
//			max_ending_here = max_ending_here + a[i];
//			if (max_so_far < max_ending_here)
//				max_so_far = max_ending_here;
//
//			if (max_ending_here < 0)
//				max_ending_here = 0;
//		}
//		return max_so_far;
//	}
//	
//	std::vector<int> maxSumDataFromStart(const std::vector<int>& a) {
//		int max_so_far = std::numeric_limits<int>::min(), max_ending_here = 0;
//		
//		std::vector<int> max_so_far_from_left(a.size(), max_so_far);
//		
//		for (int i = 0; i < a.size(); i++)
//		{
//			max_ending_here = max_ending_here + a[i];
//			if (max_so_far < max_ending_here)
//				max_so_far = max_ending_here;			
//			max_so_far_from_left[i] = max_so_far;
//		}
//		return max_so_far_from_left;
//	}    
//};
//
//
//int main() {
//    
//    std::map<std::vector<int>, int> testcases{
//        {{1, -2, -2, 12}, 13},
//        {{1,-2,3,-2}, 3},
//        {{5,-3,5}, 10},
//        {{3,-1,2,-1}, 4},
//        {{3,-2,2,-3}, 3},
//        {{-2,-3,-1}, -1},
//        {{2,-2,2,7,8,0}, 19},
//        {{0,5,8,-9,9,-7,3,-2}, 16}
//    };
//    for(auto & testcase : testcases) {
//        Solution s;
//        std::vector<int> input_vector = testcase.first;
//        int answer = s.maxSubarraySumCircularOld(input_vector);
//		int answer_another = s.maxSubarraySumCircular(testcase.first);
//        assert(testcase.second == answer);
//		assert(testcase.second == answer_another);		
//    }
//}
