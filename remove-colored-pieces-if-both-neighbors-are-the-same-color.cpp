//https://leetcode.com/contest/biweekly-contest-63/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
class Solution {
public:
    bool winnerOfGame(string colors) {
        
        char prevChar = colors[0];
        int prevCharCount = 1;
        int AChancesCount = 0,BChancesCount = 0;
        for(int i = 1; i < colors.size(); ++i) {
            if(prevChar == colors[i]) {
                prevCharCount++;
            } else {
                //char ended here count what was it
                if(prevChar == 'A') {
                    AChancesCount += (prevCharCount >= 3 ? prevCharCount - 2 : 0);
                } else {
                    BChancesCount += (prevCharCount >= 3 ? prevCharCount - 2 : 0);
                }
                prevCharCount = 1;
            }
            prevChar = colors[i];
        }
        
        if(prevChar == 'A') {
            AChancesCount += (prevCharCount >= 3 ? prevCharCount - 2 : 0);
        } else {
            BChancesCount += (prevCharCount >= 3 ? prevCharCount - 2 : 0);
        }
        
        if(AChancesCount > BChancesCount)
            return true;
        else
            return false;
    }
};
