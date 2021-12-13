//https://leetcode.com/problems/consecutive-characters/
class Solution {
public:
    int maxPower(string s) {                
        char prevChar = ' ';
        int currentPower = 0;
        int maxPower = 0;
        for(auto ch : s) {
            if( ch == prevChar) {               
                currentPower++;                
            } else {                                
                maxPower = std::max(maxPower, currentPower);
                currentPower = 1;
            }
            prevChar = ch;
        }    
        maxPower = std::max(maxPower, currentPower);
        return maxPower;
    }
};
