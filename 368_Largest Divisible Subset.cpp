////https://leetcode.com/problems/largest-divisible-subset/
//
//#include <vector>
//#include <algorithm>
//
//class Solution {
//public:
//    std::vector<int> largestDivisibleSubset(std::vector<int> & nums) {
//
//        int n = nums.size();
//
//        if (n == 0)
//            return {};
//
//        //Sort the Array
//        std::sort(nums.begin(), nums.end());
//
//        // here dp[i] : longest subset , satisfying given condition and ending at index i
//        // Initially every elements is contributing to  1 length subset.
//        std::vector<int> dp(n, 1);
//
//        // What are the elements that are present in the longest subset
//        std::vector<int> previous_indices(n, -1);
//
//        int max_index = 0; 
//
//        for (int i = 1; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
//                    dp[i] = dp[j] + 1;
//                    previous_indices[i] = j;
//                }
//            }
//
//            if (dp[i] > dp[max_index]) {
//                max_index = i;
//            }
//        }
//
//
//        std::vector<int> answer;
//        while (max_index >= 0) {
//            answer.push_back(nums[max_index]);
//            max_index = previous_indices[max_index];
//        }
//
//        return answer;
//    }
//};
//
//int main() {
//    Solution s;
//    std::vector<int> input({ 1,2,4,8 });
//    s.largestDivisibleSubset(input);
//}