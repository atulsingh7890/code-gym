class NumMatrix {
    std::vector<std::vector<int>> presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() != 0) {
            presum.resize(matrix.size(), std::vector<int>(matrix[0].size(), 0));
        
            presum[0][0] = matrix[0][0];

            for(int i = 1; i < matrix.size(); ++i) {
                presum[i][0] = presum[i-1][0] + matrix[i][0];
            }
            for(int j = 1; j < matrix[0].size(); ++j) {
                presum[0][j] = presum[0][j-1] + matrix[0][j];
            }
            for(int i = 1 ; i < matrix.size(); ++i) {
                for(int j = 1; j < matrix[0].size(); ++j) {
                    presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top_right_sum = row1 > 0 ? presum[row1-1][col2] : 0;
        int top_left_corner = row1 > 0 && col1 > 0 ? presum[row1-1][col1-1] : 0;
        int bot_right_sum = col1 > 0 ? presum[row2][col1-1] : 0;
        return presum[row2][col2] - top_right_sum - bot_right_sum + top_left_corner;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
