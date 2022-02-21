class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto Sorter = [](const std::vector<int> & a, const std::vector<int> & b) {
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] < b[1];
            else
                return false;
        };
        // b is contained in a, check
        auto isContained = [](const std::vector<int> & a, const std::vector<int> & b) {
            // b contained in a, or a contained in b
            return (a[0] <= b[0] && a[1] >= b[1]) ||  (b[0] <= a[0] && b[1] >= a[1]);
        };
        
        std::sort(intervals.begin(), intervals.end(), Sorter);
        
        int active_interval = 0;
        int result = 0;
        for(int i = 1; i < intervals.size(); ++i) {
            if(isContained(intervals[active_interval],intervals[i])) {
                result++;
                active_interval = intervals[active_interval][1] > intervals[i][1] ? active_interval : i;
            } else {
                active_interval = intervals[active_interval][1] > intervals[i][1] ? active_interval : i;
            }
        }
        return intervals.size() - result;
    }
};
