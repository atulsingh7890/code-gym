//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3734/
class Solution {
public:
    int minDistance(string word1, string word2) {
        std::vector<std::vector<int>> lcs(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        
        for(int i = 0; i <= word1.size(); i++) {
            for(int j = 0; j <= word2.size(); ++j) {
                if(i ==0 || j == 0)
                    continue;
                
                if(word1[i-1] == word2[j-1]) {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                } else {
                    lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * lcs[word1.size()][word2.size()];        
    }
};
