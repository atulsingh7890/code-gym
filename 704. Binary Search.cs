public class Solution {
    public int Search(int[] nums, int target) {
        int low = 0, high = nums.Length - 1;
        while( low <= high) {  // converging window size of 1            
            int mid = low + ( high - low)/2;  // mid biased towards low, does not matter because window size is 1            
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                low = mid + 1;  // since window size is 1, low and mid should be neighbour of mid 
            } else {
                high = mid - 1;
            }
        }
        
        // should have been found earlier
        return -1;
    }
}
