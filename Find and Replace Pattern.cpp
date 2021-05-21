//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3750/

class Solution {
    bool check_bijection(std::string &word, std::vector<int> & pattern_indices) {
        bool result = true;
        
        
        if(word.size() != pattern_indices.size()) {
            result = false;
        } else {            
            std::unordered_map<int,char> pattern_reverse_indices;        
            std::unordered_set<char> chars_already_mapped;
            
            for(int i = 0; i < word.size(); ++i) {
                //find the index of this char
                int index = pattern_indices[i];
                //find the character that should be present here
                auto it = pattern_reverse_indices.find(index);
                
                if(it == pattern_reverse_indices.end()) {
                    //check if this char is already mapped
                    auto mapped_index_it = chars_already_mapped.find(word[i]);
                    if(mapped_index_it == chars_already_mapped.end()) {
                        // first occurrence of new char, map this with current character
                        pattern_reverse_indices[index] = word[i];
                        chars_already_mapped.insert(word[i]);
                    } else {
                        result = false;
                        break;
                    }
                } else {
                    // check if reverse mapping gives the same char
                    if(word[i] != pattern_reverse_indices[index]) {
                        result = false;
                        break;
                    }
                }
            }
        }
        return result;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        std::unordered_map<char,int> pattern_bijection;
        std::vector<int> pattern_indices;
        
        int index = 0;
        for(auto ch : pattern) {
            auto it = pattern_bijection.find(ch);
            if(it == pattern_bijection.end()) {
                pattern_bijection[ch] = index++; 
            }    
            pattern_indices.push_back(pattern_bijection[ch]);
        }
        
        
        // now we have a bijection like a--> 0, b--->1 , d-->2
        
        std::vector<std::string> result;
        for(auto & word : words) {
            if(check_bijection(word, pattern_indices)) {
                result.push_back(word);
            }
        }
        return result;
    }
};
