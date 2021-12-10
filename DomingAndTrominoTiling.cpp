//https://leetcode.com/problems/domino-and-tromino-tiling/
class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        
        if(n <= 2) {
            return n;
        }
        
        long fullcovered[n+1];
        long partialyCovered[n+1];
        
        fullcovered[0] = 0;
        partialyCovered[0] = 0;
        
        fullcovered[1] = 1;  // 1 Vertical Domino
        partialyCovered[1] = 0;
        
        fullcovered[2] = 2;  // 2 Vertical and 2 Horizontal Domino
        partialyCovered[2] = 1; // 1 Tromino
        
        for(int i = 3; i < n + 1; ++i) {
            fullcovered[i] = (fullcovered[i-1] + fullcovered[i-2] + 2 * partialyCovered[i-1]) % mod;
            partialyCovered[i] = (partialyCovered[i-1] + fullcovered[i-2]) % mod;
        }
        
        return fullcovered[n];
    }
};
