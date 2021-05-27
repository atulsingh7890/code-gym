//https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3757/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        std::vector<std::pair<int,int>> representations;
        for(auto & word : words) {
            int bit_mask_representation = 0;
            for(auto ch : word) {
                bit_mask_representation = bit_mask_representation | (1 << (ch-'a'));
            }
            representations.push_back({bit_mask_representation, word.size()});
        }
        
        int result = 0;
        for(int i = 0; i < representations.size(); ++i) {
            for(int j = i+1; j < representations.size(); ++j) {
                if((representations[i].first & representations[j].first) == 0) {                    
                   result = std::max(result, representations[i].second * representations[j].second);
                }
            }
        }
        return result;
    }
};
