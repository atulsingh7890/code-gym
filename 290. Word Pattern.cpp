class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        std::vector<std::string> words;
        stringstream ss(s);
        std::string word;
        while(std::getline(ss, word, ' ')) {
            words.push_back(word);
        }
        
        if(pattern.size() != words.size())
            return false;
        
        std::unordered_map<char, std::string> bijection_pattern_to_string;
        std::unordered_map<std::string, char> bijection_string_to_pattern;
        int i = 0,j = 0;
        while ( i < pattern.size() && j < words.size()) {
            
            char ch = pattern[i];
            std::string word = words[j];
            auto it_p_to_s = bijection_pattern_to_string.find(ch);
            auto it_s_to_p = bijection_string_to_pattern.find(word);
            if(it_p_to_s == bijection_pattern_to_string.end() && it_s_to_p == bijection_string_to_pattern.end()) {
                bijection_pattern_to_string[ch] = word;
                bijection_string_to_pattern[word] = ch;
            } else if(it_p_to_s == bijection_pattern_to_string.end() || it_s_to_p == bijection_string_to_pattern.end()) {
                break;
            } else if(it_p_to_s->second != word || it_s_to_p->second != ch) {
                break;
            }
            i++,j++;
        }
        
        if(i != pattern.size() || j != words.size()) {
            return false;
        }
        return true;
    }
};
