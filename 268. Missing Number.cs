public class Solution {
    public int MissingNumber(int[] nums) {
        int actualXOR = 0;
        for(int i = 1; i <=nums.Length ; ++i)
            actualXOR ^= i;
        
        actualXOR ^= nums[0];
        
        for(int i = 1; i < nums.Length; ++i)
            actualXOR ^= nums[i];
        
        return actualXOR;
    }
}
