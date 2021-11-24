// https://leetcode.com/problems/interval-list-intersections/
class Solution {
    bool areOverlapping(const std::vector<int> & a, const std::vector<int> &b) {
        return !(a[1] < b[0] || a[0] > b[1]);
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int i = 0, j = 0;
        std::vector<std::vector<int>> result;
        while(i < firstList.size() && j < secondList.size() ) {
            if(areOverlapping(firstList[i], secondList[j])) {
                result.push_back({
                    std::max(firstList[i][0], secondList[j][0]),
                    std::min(firstList[i][1], secondList[j][1])
                });
            }
            
            if(firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        
        return result;
    }
};
