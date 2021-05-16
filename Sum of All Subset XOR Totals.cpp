//https://leetcode.com/contest/weekly-contest-241/problems/sum-of-all-subset-xor-totals/
class Solution {
public:
    int xorSum(std::vector<int> & arr) {
        int xor_ = 0;
        
        for(auto n : arr) {
            xor_ |= n;
        }
        
        xor_ = xor_ * std::pow(2, arr.size() - 1);
        return xor_;
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        return xorSum(nums);
    }
};
