//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3793/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        std::vector<int> left_to_right(ratings.size(), 1);
        std::vector<int> right_to_left(ratings.size(), 1);
        
        // first do a left to right pass
        for(int i = 1; i < ratings.size(); ++i) {
            if(ratings[i] > ratings[i-1]) {
                left_to_right[i] = left_to_right[i-1] + 1;
            }
        }
        
        // now do a right to left pass
        for(int i = ratings.size() - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i+1]) {
                right_to_left[i] = right_to_left[i+1] + 1;
            }
        }
        
        
        // aggregate the max from each elements
        int result = 0;
        for(int i = 0;  i < ratings.size(); ++i) {
            result += std::max(left_to_right[i], right_to_left[i]);
        }
        return result;
    }
};
