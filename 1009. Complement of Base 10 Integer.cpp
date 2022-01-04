class Solution {
public:
    int bitwiseComplement(int N) {
        int bitMask = 1;
        while (bitMask < N)
            bitMask = (bitMask << 1) + 1;
        return N ^ bitMask;
    }
};
