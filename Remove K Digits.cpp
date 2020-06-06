//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//#include <cassert>
//
//class Solution {	
//public:
//	std::string removeKdigits(std::string num, int k) {
//		if (k == 0) {
//			// Remove any trailing zeros if it has	
//			num.erase(0, num.find_first_not_of('0'));
//			return num.size() ? num : "0";
//		}
//		if (num.size() == k) {
//			return "0";
//		}
//
//		if (num.size() <= k) {
//			return "0";
//		}
//
//		if (num[0] == '0') {
//			return removeKdigits(std::string(num.begin() + 1, num.end()), k);
//		}
//
//		// First is non-zero and second digit is zero 
//		// Remove the first non-zero and remove the trailing for free , assuming we do not have any trailing zeroes
//		if (num[1] == '0') {
//			return removeKdigits(std::string(num.begin() + 2, num.end()), k - 1);
//		}
//				
//		// We do not have closest zero with k delete the first maximum , till the first zero index	
//		bool char_deleted = false;
//		for (int i = 0; i < num.size() - 1; ++i) {			
//			if (num[i] > num[i + 1]) {								
//				num.erase(num.begin() + i);
//				char_deleted = true;
//				break;
//			}		
//			
//		}				
//
//		if (!char_deleted) {
//			num.erase(num.end() - 1);
//		}
//
//		return removeKdigits(num, k - 1);
//		
//	}	
//};
//
//int main() {
//	{
//		std::map<std::pair<std::string, int>, std::string> testcases = {
//		{{"12", 2}, "0"},
//		{{"1432219", 3}, "1219"},
//		{{"10200", 1}, "200"},
//		{{"1432219", 1}, "132219"},
//		{{"1432219", 4}, "119"},
//		{{"1000009", 2}, "0"},
//		{{"100439", 2}, "39"},
//		{{"100439", 1}, "439"},
//		{{"100439", 3}, "3"},
//		{{"104040309", 3}, "309"},
//		{{"104040309", 5}, "0"},
//		{{"10", 1}, "0"},
//		{{"5337", 2}, "33"},
//		{{"533705", 2}, "3305"},
//		{{"5303705", 2}, "3705"},
//		{{"123405", 5}, "0"},
//		{{"1234005", 5}, "0"},
//		};
//		for (auto & test_case : testcases) {
//			Solution s;
//			std::string answer = s.removeKdigits(test_case.first.first, test_case.first.second);
//			assert(answer == test_case.second);
//		}
//	}
//}