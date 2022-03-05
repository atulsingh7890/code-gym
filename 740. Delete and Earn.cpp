class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        /*
        
        */
        std::map<int,int> count_map;
        for(auto n : nums) {
            count_map[n]++;
        }
        
        //now we have a count_map
        std::vector<int> dp(nums.size(), 0);
        dp[0] = count_map.begin()->first * count_map.begin()->second;
        int prevValue = count_map.begin()->first;
        int indexInDP = 1;
        for(auto it = std::next(count_map.begin()); it != count_map.end(); ++it) {
            //std::cout << "Processing c value " << it->first << "\n";
            int benefitFromCurrentValue = it->first * it->second;
            if(prevValue + 1 == it->first) {
                // there is a decision to make at this value
                dp[indexInDP] = std::max(
                    (indexInDP > 1 ? dp[indexInDP - 2] : 0)  + benefitFromCurrentValue,  //pick current
                    dp[indexInDP-1]  // skip current
                );
            } else {
                dp[indexInDP] = dp[indexInDP-1]  + benefitFromCurrentValue;
            }
            //std::cout << "Processing c value : Benefit " << dp[indexInDP] << "\n";
            prevValue = it->first;
            indexInDP++;
        }
        
        return dp[indexInDP-1];
    }
};
