class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        /*
        lets say grid has C columns, then we need to assume final position of Robots as i,j
        dp[r][i][j] : Sum when Robots are at Row R and Robot1 is at position i and Robot2 is at position j
        dp[r][i][j] = grid[r][i] + grid[r][j] if i !=j
                + max( of following
            dp[r+1][x][y] where x and y is picked up from cartesian product of [i-1,i,i+1] and [j-1][j][j+1]
            i.e 9 Previous Positions {r+1}
            
    
        i and j is within 0 and C    we can fill from bottom up assuming that robots are reaching at i and j and then upper row's result will depende on bottom row
        */
        
        const int rows = grid.size();
        const int cols = grid[0].size();
        std::vector<std::vector<std::vector<int>>> three_dim_dp(rows, std::vector<std::vector<int>>(cols, std::vector<int>(cols, 0)));
        
        
        std::vector<int> prev_positions{-1,0,1};
        
        auto isValid = [&rows,&cols](int r, int c) {
            return r >= 0 && r < rows && c >= 0 && c < cols; 
        };
        
        for(int r = rows-1; r >= 0; --r) {
            for(int robot_1 = 0; robot_1 < cols; ++robot_1) {
                for(int robot_2 = 0; robot_2 < cols; ++robot_2) {
                    
                    // if both are at same position add result only once
                    three_dim_dp[r][robot_1][robot_2] = (robot_1 != robot_2) ? (grid[r][robot_1] + grid[r][robot_2]) : grid[r][robot_1];
  
                    //cartesian product of previous locations
                    int max_from_previous_bottom_locations = 0;
                    for(int i = -1; i <= 1; ++i) {
                        for(int j = -1; j <= 1; ++j) {
                            // use the result from the bottom row and fill towards up
                            int prev_robot_1 = i + robot_1;
                            int prev_robot_2 = j + robot_2;

                            if(isValid(r+1, prev_robot_1) && isValid(r+1, prev_robot_2)) {

                                max_from_previous_bottom_locations = std::max(max_from_previous_bottom_locations,three_dim_dp[r+1][prev_robot_1][prev_robot_2]);
                            }
                        }
                    }
                    three_dim_dp[r][robot_1][robot_2] += max_from_previous_bottom_locations;
                }
            }
            
        }
        
        
        return three_dim_dp[0][0][cols-1];
        
    }
};
