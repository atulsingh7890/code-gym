class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(auto acc : accounts ) {            
            maxWealth = std::max(maxWealth, std::accumulate(acc.begin(), acc.end(), 0));
        }
        return maxWealth;
    }
};
