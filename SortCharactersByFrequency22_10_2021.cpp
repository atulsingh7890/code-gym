// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char,int> freqMap;
        for_each(s.begin(), s.end(), [&freqMap](char ch){ freqMap[ch]++; });
        std::sort(s.begin(), s.end(), [&freqMap](const char & a, const char &b){
            if(freqMap[a] > freqMap[b]) {return true; } else if(freqMap[a] == freqMap[b]){return a < b;} else  { return false;}
        });
        return s;
    }
};
