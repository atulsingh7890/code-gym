class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return {};
        
        std::array<int,26> window_freq;
        std::array<int,26> pattern_freq;
        
        std::fill(window_freq.begin(), window_freq.end(), 0);
        std::fill(pattern_freq.begin(), pattern_freq.end(), 0);
        
        std::vector<int> result;
        for(int i = 0; i < s.size(); ++i) {
            if(i < p.size()) {
                window_freq[s[i] - 'a']++;
                pattern_freq[p[i] - 'a']++;
            } else {
                //check if current is an anagram
                if(isFreqArrayEqual(window_freq, pattern_freq)) {
                    result.push_back(i - p.size());
                }
                
                window_freq[s[i - p.size()] - 'a']--;
                window_freq[s[i] - 'a']++;
            }
        }
        
        //check if current is an anagram
        if(isFreqArrayEqual(window_freq, pattern_freq)) {
            result.push_back(s.size() - p.size());
        }
        
        return result;
        
    }
private:
    bool isFreqArrayEqual(const std::array<int,26> & a, const std::array<int,26> & b) {
        bool result = true;
        for(int i = 0; i < 26; ++i) {
            if(a[i] != b[i]) {
                result = false;
                break;
            }
        }
        return result;
    }
};
