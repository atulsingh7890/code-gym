class Solution {
    bool is_subset_possible(const std::vector<int> & nums, int current_index, int sum) {
        if(sum == 0)
            return true;
        
        if(current_index == 0 && sum != 0)
            return false;
        
        //include/exclude last element
        return is_subset_possible(nums, current_index - 1, sum - nums[current_index]) ||
            is_subset_possible(nums, current_index - 1, sum);
    }
    bool is_subset_possible(const std::vector<int> & nums, int sum) {
        bool dp[nums.size() + 1][sum + 1];
        for(int i = 0; i <= nums.size(); ++i) {
            for(int j = 0; j <= sum; ++j) {
                if(i==0)
                    dp[i][j] = false;
                if(j==0)
                    dp[i][j] = true;
            }
        }
        
        
        for(int i = 1; i <= nums.size(); ++i) {
            for(int j = 1; j <= sum; ++j) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(auto n : nums) {
            total_sum += n;
        }
        
        if(total_sum % 2 != 0)
            return false;            
        
        //return is_subset_possible(nums, nums.size() - 1, total_sum/2);
        return is_subset_possible(nums, total_sum/2);
    }
    
};
