//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            const int n = nums[i];
            curSum = std::max(n, curSum + n);
            maxSum = std::max(curSum, maxSum);
        }
        return maxSum;
    }
};
