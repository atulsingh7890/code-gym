class Solution {
public:
    int countOrders(int n) {
        /*
        dp[i]  = valid pickup for i orders
        lets calculate for dp[i+1]
        // 2 * i : lenght of preivous order length
        A : Keep New order pair as it is between 2 * (i-1) + 1 slots
            = (2 * (i-1) + 1) * dp[i-1]
        Bk : Keeping New order pickkup at Position i in 2*i + 1 slots
             k will vary from 0 to (2*(i-1) + 1) - 2 slots, 
             i.e for when (P1,P2,D2,D1) : i = 0 to 3, (2*2  + 1 - 2) = 3
             = dp[i-1] * ( 2*(i-1) - k) | k varies from 0 to 2*(i-1) + 1 - 2
             
        dp[i+1] = A + Bk
        */
        const long mod = 1e9 + 7;
        std::vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            long A = (((2 * (i-1) + 1)) * (dp[i-1] % mod)) % mod;
            long Bk = 0;
            for(int k = 0; k <= (2*(i-1) - 1); ++k) {
                long keepingAtPosition = ((dp[i-1] % mod) * (2*(i-1) - k) % mod) % mod;
                Bk += keepingAtPosition;
            }
            
            dp[i] = (A % mod + Bk % mod) % mod;
        }
        
        return dp[n];
    }
};
