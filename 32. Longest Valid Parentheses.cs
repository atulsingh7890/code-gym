public class Solution {
    // public int LongestValidParentheses(string s) {
    //     int[] dp = new int[s.Length];
    //     int result = 0;
    //     for(int i = 1; i < s.Length; ++i) {
    //         if(s[i] == ')') {
    //             if(s[i-1] == '(') {
    //                 dp[i] = (i >= 2 ? dp[i-2] : 0 ) + 2;
    //             } else if((i - dp[i-1]) > 0 && s[i-dp[i-1] - 1] == '(' ){
    //                 dp[i] = dp[i-1] + ( (i-dp[i-1]) >= 2 ? dp[i - dp[i-1] - 2] : 0) + 2;
    //             }                
    //         }
    //         result = Math.Max(result, dp[i]);            
    //     }
    //     return result;
    // }
    
    public int LongestValidParentheses(string s) {
        int left = 0, right = 0;
        int result = 0;
        // first traverse from left to right
        for(int i = 0; i < s.Length; ++i) {
            _ = s[i] == '(' ? left++ : right++;
            
            if(left == right) {
                result = Math.Max(result, left + right);
            } else if(right > left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        // now traverse from right to left
        for(int i = s.Length - 1; i >= 0; --i) {
            _ = s[i] == '(' ? left++ : right++;
            
            if(left == right) {
                result = Math.Max(result, left + right);
            } else if(left > right) {
                left = right = 0;
            }
        }
        
        return result;
    }
}
