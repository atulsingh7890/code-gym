// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3793/
public class Solution {
    public int Candy(int[] ratings) {
        int[] left_2_right = Enumerable.Range(0, ratings.Length).Select(n => 1).ToArray();
        int[] right_2_left = Enumerable.Range(0, ratings.Length).Select(n => 1).ToArray();
        
        for(int i = 1; i < ratings.Length; ++i) {
            if(ratings[i] > ratings[i-1]) {
                left_2_right[i] = left_2_right[i-1] + 1;
            }
        }
        
        for(int i = ratings.Length - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i+1]) {
                right_2_left[i] = right_2_left[i+1] + 1;
            }
        }
        
        int result = 0;
        for(int i = 0; i < ratings.Length; ++i) {
            result += Math.Max(left_2_right[i], right_2_left[i]);
        }
        
        return result;
    }
}
