//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/

class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> jumps(nums.size(), std::numeric_limits<int>::max());
        
        jumps[0] = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            
            int jumps_allowed_from_current_position = nums[i];
            
            for(int j = 1; j <= jumps_allowed_from_current_position && j + i < jumps.size(); ++j) {                
                
                jumps[j+i] = std::min(jumps[j+i], jumps[i] + 1);                
                
            }            
        }
        
        return jumps[jumps.size()-1];
    }
};
