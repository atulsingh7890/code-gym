public class Solution {
    public int BrokenCalc(int startValue, int target) 
    {
        if(startValue >= target)
        {
            // muliply would further increase the gap, lets subtract and come closer
            // to our target which is smaller
            return startValue - target;
        }
        
        if(target % 2 == 0)
        {
            return 1 + BrokenCalc(startValue, target/2);
        }
        else 
        {
            return 1 + BrokenCalc(startValue, target + 1);
        }
    }
}
