class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 0 or grid[0][0] != 0)
            return -1;
        
        const int r = grid.size();
        const int c = grid[0].size();
        
        std::queue<std::pair<int,int>> q;
        
        q.push({0,0});
        grid[0][0]= 2; // 2 means its visited
        
        int result = 0;
        bool resultFound = false;
        while(false == q.empty() and false == resultFound) {
            // process the q completely for this Bread , then we will go for next level
            int qsize = q.size();
            
            // one q pass is like visiting all  its neighbours
            result++;
            
            for(int i = 0; i < qsize; ++i) {
                                
                
                std::pair<int,int> current = q.front(); q.pop();
                
                if(current.first == r - 1 and current.second == c - 1) {
                    resultFound = true;
                    break;
                }
                
                for(int j = -1; j <= 1; ++j) {
                    for(int k = -1; k <= 1; ++k) {
                        int nj = current.first + j;
                        int nk = current.second + k;
                        if(nj >= 0 and nj < r and nk >= 0 and nk < c and grid[nj][nk] == 0) {
                            q.push({nj,nk});
                            grid[nj][nk] = 2;  // mark it as visited
                        }
                    }
                }                
            }
        }
        return resultFound ? result : -1;
    }
};
