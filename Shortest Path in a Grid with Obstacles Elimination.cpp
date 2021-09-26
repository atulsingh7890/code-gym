class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, -1));
        
        std::queue<std::vector<int>> q;
        //x,y,currentLength,remaining k
        q.push({0,0,0,k});
        while(false == q.empty()) {
            auto cur = q.front(); q.pop();
            
            int x = cur[0], y = cur[1];
            if(x < 0 || x >= rows || y < 0 || y >= cols)
                continue;
            
            if(x == rows - 1 && y == cols - 1)
                return cur[2];
            
            //we hit any obstacle
            if(grid[x][y] == 1) {
                if(cur[3] > 0) {
                    cur[3]--;
                }
                else
                    continue;
            }
            
            // this celll is already visited where we had more Ks, then reserve K
            if(visited[x][y] != -1 && visited[x][y] >= cur[3]) {
                continue;
            }
            
            // put the value of k we have reached till this point in visited array
            visited[x][y] = cur[3];
            
            q.push({x+1, y, cur[2]+1, cur[3]});
            q.push({x-1, y, cur[2]+1, cur[3]});
            q.push({x, y+1, cur[2]+1, cur[3]});
            q.push({x, y-1, cur[2]+1, cur[3]});
            
        }
        
        return -1;
    }
};
