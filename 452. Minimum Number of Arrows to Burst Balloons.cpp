class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::vector<std::vector<int>> merged;
        std::sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> & b){
            return a[0] < b[0];
        });
        
        auto isOverlapping = [](const std::vector<int> & a, const std::vector<int> & b){
            return !(a[0] > b[1] || a[1] < b[0]);
        };
        
        merged.push_back(points[0]);
        for(int i = 1; i < points.size(); ++i) {
            if(isOverlapping(merged.back(), points[i])) {
                merged[merged.size()-1] = {
                    std::max(merged.back()[0], points[i][0]),
                    std::min(merged.back()[1], points[i][1])
                };
            } else {
                merged.push_back(points[i]);
            }
        }
        
        return merged.size();
    }
};
