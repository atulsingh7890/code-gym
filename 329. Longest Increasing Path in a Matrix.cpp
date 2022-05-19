class Solution {    
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
                
        // we will store the results of each Longest Increasing Path for each cell
        // and then reuse for cells as we go on
        // -1 is yet to be computed
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int ans = 0;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                int lip = dfs(matrix, i, j, dp, std::numeric_limits<int>::min());
                ans = max(ans, lip);
            }
        }
        
        return ans;
    }
private:
    vector<vector<int>> neighbours = {{-1,0},{0,-1},{0,1},{1,0}};
    
    // find longest increasing path starting at [r,c]
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>> & dp, int prev) {
        
        if(r < 0 || r >= matrix.size() || c < 0 || c >= matrix[r].size() ) {
            return 0; 
        }
                
        // if current element is less than the prev then return 0    
        if(matrix[r][c] <= prev) { 
            return 0;
        }
        
        if(dp[r][c] != -1) { 
            return dp[r][c];
        }
        
        int longestIncreasingPath = 0;        
        for(auto& neighbour : neighbours) {
            int nr = neighbour[0] + r;
            int nc = neighbour[1] + c;
            int cur = dfs(matrix, nr, nc, dp, matrix[r][c]);
            longestIncreasingPath = max(longestIncreasingPath, cur);
        }
        
        dp[r][c] = longestIncreasingPath + 1;
        return dp[r][c];
    }
};
