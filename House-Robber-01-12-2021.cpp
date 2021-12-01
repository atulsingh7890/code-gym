//https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dp(nums.size(), -1);
        return rob(nums, 0, dp);        
    }
    
    int rob(std::vector<int> & nums, int index, std::vector<int> & dp) {
        if( index >= nums.size())
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int skip = rob(nums, index + 1, dp);
        int robbed = nums[index] + rob(nums, index + 2, dp);
        
        dp[index] = std::max(skip, robbed);
        return dp[index];
    }
};
