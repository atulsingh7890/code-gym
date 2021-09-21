class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLength = 0;
        int currentLength = 0;
        for(int i = 0; i < nums.size(); ++i) {
            currentLength = nums[i] ? currentLength + 1 : 0;
            maxLength = std::max(maxLength, currentLength);
        }
        return maxLength;
    }
};
