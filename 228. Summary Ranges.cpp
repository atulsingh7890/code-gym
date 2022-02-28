class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.size() == 0)
            return {};
        
        std::vector<std::pair<int,int>> intervals;
        intervals.push_back({nums[0],nums[0]});
        
        for(int i = 1; i < nums.size(); ++i) {
            if(intervals.back().second + 1 == nums[i]) {
                intervals.back().second += 1;
            } else {
                intervals.push_back({nums[i],nums[i]});
            }
        }
        
        std::vector<std::string> result;
        for(auto interval : intervals) {
            if(interval.first == interval.second) {
                result.push_back(std::to_string(interval.first));
            } else {
                result.push_back(std::to_string(interval.first) + "->" + std::to_string(interval.second));
            }
        }
        return result;
                             
    }
};
