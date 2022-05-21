public class Solution {
    public int CoinChange(int[] coins, int amount) {
        Array.Sort(coins);
        int[] dp = new int[amount + 1];
        Array.Fill(dp, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            int minimumCoins = Int32.MaxValue;
            foreach(int coin in coins) {
                if( i - coin < 0) {
                    break;
                }
                if( dp[i - coin] != -1) {
                    minimumCoins = Math.Min(minimumCoins, dp[i - coin]);
                }
            }
            
            if(minimumCoins != Int32.MaxValue) {
                dp[i] = minimumCoins + 1;
            }
        }
        return dp[amount];
    }
}
