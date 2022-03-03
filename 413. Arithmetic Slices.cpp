class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int slicesCount = 0;
        int size = nums.size();
        for(int sliceStart = 0; sliceStart < size - 2; ++sliceStart) {
            // lets count slices starting at i
            int sliceEnd = sliceStart + 2;
            while(sliceEnd < size && nums[sliceStart+1] - nums[sliceStart] == nums[sliceEnd] - nums[sliceEnd-1]) {
                sliceEnd++;
                slicesCount++;
            }
        }
        
        return slicesCount;
    }
};
