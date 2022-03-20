public class Solution {
    public int MinDominoRotations(int[] tops, int[] bottoms)
    {
        int[] topsCount = new int[7];  // 0 is default initialization
        int[] bottomCount  = new int[7];
        int[] sameCount = new int[7];
        for(int i = 0; i < tops.Length; ++i)
        {
            topsCount[tops[i]]++;
            bottomCount[bottoms[i]]++;
            if(tops[i] == bottoms[i])
            {
                sameCount[tops[i]]++;
            }
        }
        
        //now we can make dominos from 1 to 6, lets see which face value satisfies the eqn
        int minRotation = Int32.MaxValue;
        for(int i = 1; i <= 6; ++i)
        {
            if(topsCount[i] + bottomCount[i] - sameCount[i] == tops.Length)
            {
                minRotation = Math.Min(minRotation, Math.Min(topsCount[i], bottomCount[i]) - sameCount[i]);
            }
        }
        return minRotation != Int32.MaxValue ? minRotation : -1;
    }
}
