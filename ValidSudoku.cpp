class Solution {
private :
    bool checkColumn(std::vector<std::vector<char>> & board, int col_index) 
    {
        std::unordered_set<char> seen;
        bool result = true;
        
        for(int i = 0; i < 9; ++i) {
            if(board[i][col_index] != '.') {
                auto it = seen.find(board[i][col_index]);
                if(it != seen.end()) {
                    result = false;
                    break;
                }
                seen.insert(board[i][col_index]);
            }
        }
        return result;
    }
    bool checkRow(std::vector<std::vector<char>> & board, int row_index) 
    {
        std::unordered_set<char> seen;
        bool result = true;
        
        for(int i = 0; i < 9; ++i) {
            if(board[row_index][i] != '.') {
                auto it = seen.find(board[row_index][i]);
                if(it != seen.end()) {
                    result = false;
                    break;
                }
                seen.insert(board[row_index][i]);
            }
        }
        return result;
    }
    
    bool checkBlock(std::vector<std::vector<char>> & board, int block_r,int block_c) {
        std::unordered_set<char> seen;
        bool result = true;
        
        for(int i = block_r; i < block_r + 3; ++i) {
            for(int j = block_c; j < block_c + 3; ++j) {
                if(board[i][j] != '.') {
                    auto it = seen.find(board[i][j]);
                    if(it != seen.end()) {
                        result = false;
                        break;
                    }
                    seen.insert(board[i][j]);
                }
            }
        }
        return result;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = true;
        
        for(int i = 0; i < 9 && result; ++i) {
            result = checkRow(board, i);
            if(false == result) {
                break;
            }
        }
        
        for(int i = 0; i < 9 && result; ++i) {
            result = checkColumn(board, i);
            if(false == result) {
                break;
            }
        }
        
        for(int i = 0; i < 9 && result; i += 3) {
            for(int j = 0; j < 9 && result; j += 3) {
                result = checkBlock(board, i, j);
                if(false == result) {
                    break;
                }
            }
            if(false == result) {
                    break;
            }
        }

        
        
        return result;
    }
};
