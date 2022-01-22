class Solution {
public:
    bool winnerSquareGame(int n) {
        /* lets have an array
        dp[i] = true/false : stating wining stones
        dp[j] = find any k < j , where dp[k] is false and (j - k ) is a perfect square
        we can store this information as we build forward dp
        */
        // pair = {win, isPerfectSquare}
        std::vector<std::pair<bool,bool>> dp(n+1, {false,false});
        std::vector<int> previous_perfect_quares;
        dp[0] = {true, true};
        dp[1] = {true, true};
        previous_perfect_quares.push_back(1);
        for(int i = 2; i <= n; ++i) {
            double sqrt_i = (double)sqrt(i);
            if (ceil(sqrt_i) == floor(sqrt_i)) {
                //if its already square its a win situation
                dp[i] = {true,true};
                previous_perfect_quares.push_back(i);
            } else {
                
                /*
                TLE in 1e4
                // find a j , where dp[j] = false, and i - j is a perfect square
                // this strategy is making the other person loose
                // picking j or i - j
                for(int j = i - 1; j >= 1; --j) {
                    bool leaving_j_for_next_opponent = dp[j].first == false && dp[i - j].second == true;
                    bool leaving_i_minus_j_for_next_opponent = dp[i-j].first == false && dp[j].second == true;
                    if(leaving_j_for_next_opponent || leaving_i_minus_j_for_next_opponent) {
                        dp[i].first = true;
                        break;
                    }
                }
                */
                
                for(int j = previous_perfect_quares.size() - 1; j >= 0; --j) {
                    int another_number = previous_perfect_quares[j];
                    bool leaving_i_minus_j_for_next_opponent = dp[i - another_number].first == false;
                    if(leaving_i_minus_j_for_next_opponent) {
                        dp[i].first = true;
                    }
                }
            }
        }
        
        return dp[n].first;
    }
};
