//#include <vector>
//
//class Solution {
//public:
//    std::vector<int> findDigits(int num) {
//        std::vector<int> result;
//        while(num) {
//            int digit = num % 10;
//            result.push_back(digit);
//            num /= 10;
//        }
//        return result;
//    }    
//
//    int formNumber(std::vector<int> digits) {
//        int num = 0;
//        int multiplier = 1;
//        for( auto digit : digits) {
//            num += multiplier * digit;
//            multiplier *= 10;
//        }
//    }        
//    int maxDiff(int num) {
//        int first_non_nine_index_from_right = 0;
//        int first_non_one_index_from_right = 0;
//        
//
//    
//    }
//};
//
//int main() {
//	Solution s;
//	s.findDigits(10);
//}