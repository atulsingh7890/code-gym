public class Solution {
    public int HammingWeight(uint n) {
        int result = 0;
        while(n > 0) {
            result += (n % 2 == 0) ? 0 : 1;
            n = n >> 1;
        }
        return result;
    }
}
