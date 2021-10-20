//https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        std::reverse(s.begin(), s.end());
        int start = 0, end = 0;
        bool word_started = false;
        std::string result;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ' && word_started) {
                // word ended revere a word
                word_started = false;
            //std::cout << "start " << start << "\n";
            //std::cout << "end " << end << "\n";
                if(result.size()){
                    result.push_back(' ');
                }
                for(int k = end; k >= start; --k) {
                    result.push_back(s[k]);
                }
            } else if(s[i] != ' '){
                if(!word_started) {
                    start = i;
                    end = i;
                    word_started = true;
                } else {
                    end++;
                }
            }
        }
        
        if(word_started) {
            //std::cout << "start " << start << "\n";
            //std::cout << "end " << end << "\n";
                if(result.size()){
                    result.push_back(' ');
                }
                for(int k = end; k >= start; --k) {
                    result.push_back(s[k]);
                }
        }
        
        return result;
    }
};
