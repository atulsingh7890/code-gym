//https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3981/
class Solution {
    bool isWinner(std::vector<std::vector<char>> & moves, char toCheck) {
        // check the rows first
        bool won = false;
        for(int i = 0; i < 3; ++i) {
            won = (moves[i][0] == toCheck) && 
                  (moves[i][0] == moves[i][1]) &&
                  (moves[i][0] == moves[i][2]);
            if(won)
                break;
        }
        
        if(!won) {
            // now check columns
            for(int i = 0; i < 3; ++i) {
                won = (moves[0][i] == toCheck) && 
                      (moves[0][i] == moves[1][i]) &&
                      (moves[0][i] == moves[2][i]);
                if(won)
                    break;
            }
        }   
        
        if(!won) {
            // now check primary diagonal
            won = (moves[0][0] == toCheck) &&
                (moves[0][0] == moves[1][1]) &&
                (moves[1][1] == moves[2][2]);
        }
        
        if(!won) {
            // now check secondary diagonal
            won = (moves[0][2] == toCheck) &&
                (moves[0][2] == moves[1][1]) &&
                (moves[0][2] == moves[2][0]);
        }
        
        return won;
    }
    
    void printBoard(std::vector<std::vector<char>> & board) {
        std::cout << "\n";
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
        
        std::cout << "\n";
    }
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        std::vector<std::vector<char>> board(3, std::vector<char>(3, '.'));
        
        char playerIndex = 1;
        bool won = false;
        int open_slots = 9;
        for(int i = 0; i < moves.size(); ++i) {
            board[moves[i][0]][moves[i][1]] = playerIndex + '0';
            
            won = isWinner(board, playerIndex + '0');
            open_slots--;
            
            if(won)
                break;
            
            playerIndex = 1 - playerIndex;
            //printBoard(board);
        }
        
        if(won) {
            return playerIndex ? "A" : "B";
        } else {
            return open_slots > 0 ? "Pending" : "Draw";
        }
    }
};
