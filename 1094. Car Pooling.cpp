class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 1004 because max positin is 1000 only
        std::vector<int> positions(1004, 0);        
        for(auto & trip : trips) {
            for(int i = trip[1]; i < trip[2]; ++i) {
                positions[i] += trip[0];
                if(positions[i] > capacity)
                    return false;
            }
        }        
        return true;
    }        
};
    
