class Solution {
public:
    int minSwaps(string s) {
        int count_ones = 0;
        int count_zeros= 0;
        for(auto ch : s) {
            if(ch == '0')
                count_zeros++;
            else
                count_ones++;
        }
        
        if(std::abs(count_ones - count_zeros) > 1)
            return -1;
        
        
        char to_pick = count_ones > count_zeros ? '1' : '0';
        int picked_char_frequencies = count_ones > count_zeros ? count_ones : count_zeros;
        int remained_char_frequencies = count_ones > count_zeros ? count_zeros : count_ones;
        
        int result = 0;
        
        //std::cout << count_ones << " : count_ones\n" ;
        //std::cout << count_zeros << " : count_zeros\n" ;
        
        if(count_ones == count_zeros) {
            to_pick = '0';
            int result1 = 0;
            for(int i = 1; i < s.size(); i += 2) {
                if(s[i] == to_pick) {
                    result1++;
                }
            }
            
            int result2 = 0;
            to_pick = '1';
            for(int i = 1; i < s.size(); i += 2) {
                if(s[i] == to_pick) {
                    result2++;
                }
            }
            
            result = std::min(result1, result2);
        }                        
        else {
            for(int i = 1; i < s.size(); i += 2) {
                if(s[i] == to_pick) {
                    result++;
                }
            }
        }
         
        
        return result;
    }
};
