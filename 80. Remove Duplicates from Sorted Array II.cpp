class Solution {   
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 )
            return 0;
        
        int destination = 1;
        int freq = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1])
                freq++;
            else 
                freq = 1;
            
            if(freq <= 2){
                nums[destination++] = nums[i];
            }
        }
        return destination;
    }
};
