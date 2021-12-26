//https://leetcode.com/problems/k-closest-points-to-origin/submissions/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto comparator = [](const std::vector<int> & a, const std::vector<int> & b) {
            return 
                (a[0]*a[0] + a[1] * a[1]) <
                (b[0]*b[0] + b[1] * b[1]);
        };
        
        std::priority_queue<
            std::vector<int>,
            std::vector<std::vector<int>>,
             decltype(comparator) >  pq(comparator);
        
        for(int i = 0; i < points.size(); ++i) {
            if( i < k) {
                pq.push(points[i]);
            } else {
                pq.push(points[i]);
                pq.pop();
            }
        }
        
        std::vector<std::vector<int>> result;
        while(false == pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
