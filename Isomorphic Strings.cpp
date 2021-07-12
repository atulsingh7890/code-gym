//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3811/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size()) {
            return false;
        }
        
        bool result = true;
        std::unordered_map<char,char> char_mappings;
        std::unordered_map<char, char> reverse_char_mappings;
        
        for(int i = 0; i < s.size(); ++i) {
            auto it = char_mappings.find(s[i]);
            auto it_r = reverse_char_mappings.find(t[i]);
            if(it == char_mappings.end() && it_r == reverse_char_mappings.end()) {
                char_mappings[s[i]] = t[i];
                reverse_char_mappings[t[i]] = s[i];
            } else if(it == char_mappings.end() ||
                      it_r == reverse_char_mappings.end() || 
                      it->first != it_r->second ||
                      it->second != it_r->first) {
                result = false;
                break;
            }
        }
        
        return result;
    }
};
