//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3796/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int max_window_size = 0;
        int ones = 0, zeros = 0;
        int window_start = 0;
        for(int i = 0; i < nums.size(); ++i) {
            
            nums[i] ? ones++ : zeros++;
            
            while(zeros > k) {
                nums[window_start] ? ones-- : zeros--;
                window_start++;
            }
            
            max_window_size = std::max(max_window_size, ones + zeros);
            
        }
        return max_window_size;
    }
};
