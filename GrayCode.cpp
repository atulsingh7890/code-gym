// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3799/
class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> combinations;
        combinations.push_back(0);        
        for(int i = 1; i <= n; ++i) {
            //fist add the Binary Reflected Code from previous digit
            int previous_numbers_count = combinations.size();
            int mask = 1 << (i-1);
            for(int j = previous_numbers_count - 1; j >= 0; --j) {
                int current_number = combinations[j];
                combinations.push_back( mask | current_number);
            }            
        }
        return combinations;
        
        //return method_two(n);
    }
    
    
    std::vector<int> method_two(int n) {
        std::vector<int> result;
        int numbers_to_populate = 1 << n;
        for(int i = 0; i < numbers_to_populate; ++i) {
            result.push_back(i ^ ( i >> 1));
        }
        return result;
    }
};
