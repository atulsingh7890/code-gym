//https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3758/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int max_sum = 0;
        int window_start = 0;
        int current_window_size = 0;
        int current_window_sum = 0;
        std::unordered_map<int,int> lastseen;
        for(int i = 0; i < nums.size(); ++i) {
            
            // see if current element is duplicating in the current window            
            auto it = lastseen.find(nums[i]);
            if(it != lastseen.end()) {
                // this element is repeated, window size will be restarted now
                int last_seen_index_of_current_element = it->second;
                
                // decrease the window size till this element
                while(window_start <= last_seen_index_of_current_element) {
                    current_window_sum = current_window_sum - nums[window_start];
                    window_start++;                    
                }                
            }                        
            lastseen[nums[i]] = i;     
            current_window_sum += nums[i];
            max_sum = std::max(max_sum, current_window_sum);
        }
        return max_sum;
    }
};
