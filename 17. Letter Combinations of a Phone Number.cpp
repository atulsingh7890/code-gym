const static std::unordered_map<int, std::vector<char>> key_map{
        {2,{'a','b','c'}},
        {3,{'d','e','f'}},
        {4,{'g','h','i'}},
        {5,{'j','k','l'}},
        {6,{'m','n','o'}},
        {7,{'p','q','r','s'}},
        {8,{'t','u','v'}},
        {9,{'w','x','y','z'}},
    };
    
class Solution {
    void letterCobinations(std::string digits,
                           std::string combination_till_now,
                           int current_digit,
                          std::vector<std::string> & results) const {
        if(current_digit == digits.size()) {
            results.push_back(combination_till_now);
            return;
        }
        
        auto it = key_map.find(digits[current_digit] - '0');
        for(auto ch :  it->second) {
            combination_till_now.push_back(ch);
            letterCobinations(digits, combination_till_now, current_digit + 1, results);
            combination_till_now.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        
        std::vector<std::string> results;
        letterCobinations(digits, "", 0, results);
        return results;
    }
};
