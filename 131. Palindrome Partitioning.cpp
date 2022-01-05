class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> result;
        
        std::vector<std::string> currentSplit;
        backtrack(result, s, 0, currentSplit);
        
        return result;
    }
    
    void backtrack(std::vector<std::vector<std::string>> & collated, 
                  std::string &str,
                  int startIndex,
                  std::vector<std::string> & currentSplit) {
        if(startIndex >= str.size()) {
            collated.push_back(currentSplit);
            return;
        }
        
        
        for(int splitIndex = startIndex; splitIndex < str.size(); ++splitIndex) {
            if(isPalindrome(str,startIndex,splitIndex)) {
                // insert the current palindrome
                currentSplit.push_back(str.substr(startIndex, splitIndex - startIndex + 1));
                
                // backtrack for next remaining string
                backtrack(collated, str, splitIndex  + 1, currentSplit);
                
                // remove the state for next iteration
                currentSplit.pop_back();
            }
        }        
    }
    
    bool isPalindrome(std::string & str, int low, int high) {
        while(low < high) {
            if(str[low] != str[high])
                return false;
            low++,high--;
        }
        return true;
    }
};
