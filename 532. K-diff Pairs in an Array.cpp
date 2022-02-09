class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int result = 0;
        int i = 0;
        int j = i + 1;       
        //1,1,3,4,5
        while(i < nums.size() && j < nums.size()) {            
            while(j < nums.size() && nums[j] - nums[i] < k) {
                j++;
            }
                        
            if(nums[j] - nums[i] == k) {
                result++;
            
                // increment the end of window till we see a new unique number
                while(j + 1 < nums.size() && nums[j] == nums[j+1] )
                    j++;
                j++;
            }
        
            // increase i as well start of the window
           while(i + 1 < j  && nums[i] == nums[i+1] )
                i++;
            i++;
            
            if(i == j) {
                j++;
            }                       
            
        }
        return result;
    }
};
