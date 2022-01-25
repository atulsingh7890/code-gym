class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0)
            return true;
        
        vector<int> capital_positions;
        for(int i = 0; i < word.size(); ++i) {
            if(word[i] >= 'A' && word[i] <= 'Z')
                capital_positions.push_back(i);
        }
        
        if(capital_positions.size() == word.size())
            return true;
        
        
        return capital_positions.size() == 0  || (capital_positions.size() == 1 && capital_positions[0] == 0); 
        
                
    }
};
