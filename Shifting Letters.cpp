//https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3968/
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = shifts.size() - 2; i >= 0; --i) {
            shifts[i] = (shifts[i] + shifts[i+1])%26;
        }
        
        for(int i = 0; i < s.size(); ++i) {
            s[i] = ((s[i] - 'a') + shifts[i] % 26) % 26 + 'a';
        }
        return s;
    }
};
