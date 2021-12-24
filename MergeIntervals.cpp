//https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b){
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] < b[1];
            else
                return false;
        });
        
        
        std::vector<std::vector<int>> result;
        
        auto isOverlapping = [](const std::vector<int> &a, const std::vector<int> &b) {
            return false == (a[1] < b[0] || a[0] > b[1]);
        };
        
        for(auto interval: intervals) {
            if(result.size() == 0 || false == isOverlapping(result.back(), interval)) {
                result.push_back(interval);
            } else {
                result.back()[0] = std::min(result.back()[0], interval[0]);
                result.back()[1] = std::max(result.back()[1], interval[1]);
            }
        }
        
        return result;
        
    }
};
