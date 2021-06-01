//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/

class Solution {
    bool isValid(std::pair<int,int> e, vector<vector<int>>& grid) {
        return e.first >= 0 && e.first < grid.size() && e.second >= 0 && e.second < grid[0].size();
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        std::vector<std::vector<int>> visited(grid.size(), std::vector<int>(grid[0].size(), 0));
        
        std::vector<std::pair<int,int>> neighbours{
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };
        
        int max_area = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {                
                if(visited[i][j] == 0 && grid[i][j] == 1) {
                    
                    std::queue<std::pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    int curr_area = 0;                    
                    while(false == q.empty()) {
                        auto [r,c] = q.front(); q.pop();                        
                        curr_area++;
                        for(auto & n : neighbours) {
                            std::pair<int,int> next({n.first + r, n.second + c});
                            if(isValid(next, grid) && grid[next.first][next.second] && 0 == visited[next.first][next.second]) {
                                q.push(next);
                                visited[next.first][next.second] = 1;
                            }
                        }
                    }                    
                    max_area = std::max(max_area, curr_area);
                }
                
            }
        }
        return max_area;
    }
};
