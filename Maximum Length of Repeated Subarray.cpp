// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3807/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //similar to lcs
        std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));

        int result = 0;
        
        for(int i = 1; i <= nums1.size(); ++i) {
            for(int j = 1; j <= nums2.size(); ++j) {
              dp[i][j] = nums1[i-1] == nums2[j-1] ? dp[i-1][j-1] + 1 : 0;
                
                result = std::max(result, dp[i][j]);
            }

        }
        
        return result;
    }
};
