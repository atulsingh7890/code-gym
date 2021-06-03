class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_height = 0;
        constexpr long MOD = 1e9 + 7;
    
            
        for(int i = 1; i < horizontalCuts.size(); ++i) {
            int top_row = horizontalCuts[i-1];
            int botom_row = horizontalCuts[i];
            max_height = std::max(max_height, botom_row - top_row);
        }
        
        int max_width = 0;
        for(int j = 1; j < verticalCuts.size(); ++j) {
            int left_column = verticalCuts[j-1];
            int right_column = verticalCuts[j];
            max_width = std::max(max_width, right_column - left_column);
        }
        
        
        
        return ((max_height % MOD) * (max_width % MOD)) %  MOD;
    }
};
