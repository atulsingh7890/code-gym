class Solution {
    char toLowerCase(char ch) {
        if(ch >= 'A' && ch <= 'Z')
            return ch - 'A' + 'a';
        return ch;
    }
public:
    string toLowerCase(string s) {
        for(auto & ch : s) {
            ch = toLowerCase(ch);
        }
        return s;
    }
};
