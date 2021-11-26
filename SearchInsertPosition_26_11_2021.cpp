class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() -1 ;
        if(target < nums[0])
            return 0;
        else if(target > nums[nums.size()-1])
            return nums.size();
        while(s < e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }
};
