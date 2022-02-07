class Solution {
public:
    char findTheDifference(string s, string t) {
        std::array<int,26> freq;
        std::fill(freq.begin(), freq.end(), 0);
        for(auto ch : s) {
            freq[ch-'a']++;
        }
        
        char result = '0';        
        for(auto ch : t) {
            if(freq[ch-'a'] == 0) {
                result = ch;                
                break;
            }
            freq[ch-'a']--;
        }
        
        return result;
    }
};
