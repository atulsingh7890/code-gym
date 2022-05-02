class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even_index = 0, odd_index = nums.size() - 1;
        while(even_index < odd_index) {
            if(nums[even_index] % 2 == 0) {                
                even_index++;                
            } else {
                std::swap(nums[even_index], nums[odd_index]);
                odd_index--;
            }
        }
        return nums;
    }
};
