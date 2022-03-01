class Solution {
    bool IsPowerOfTwo(int n) {
        return (n & (n - 1)) == 0;
    }
public:
    vector<int> countBits(int num) {
        
        std::vector<int> result;
        
        if(num == 0) {
            result.push_back(0);
        } else if(num == 1) {
            result.push_back(0);
            result.push_back(1);
        } else {
            
            result.push_back(0);
            result.push_back(1);
            int last_power_of_two = 2;
        
            for(int current_number = 2; current_number <= num; ++current_number) {
                if(IsPowerOfTwo(current_number)) {
                    result.push_back(1);
                    last_power_of_two = current_number;
                } else {
                    int number_of_set_bits = 1 + result[current_number - last_power_of_two];
                    result.push_back(number_of_set_bits);
                }
            }
        }
    
        
        return result;
        
    }
};
