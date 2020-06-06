//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//
//class Solution {
//public:
//	int minNumberOfFrogs(std::string croakOfFrogs) {
//
//		std::map<std::string, int> sub_string_freq;
//		sub_string_freq["c"] = 0;
//		sub_string_freq["cr"] = 0;
//		sub_string_freq["cro"] = 0;
//		sub_string_freq["croa"] = 0;
//		sub_string_freq["croak"] = 0;
//
//		int frogs = 0;
//		int frog_count = 0;
//		int number_of_frogs = 0;
//		for (auto ch : croakOfFrogs) {
//			switch (ch)
//			{
//			case 'c': {
//				// Increment the entry with 'c'
//				sub_string_freq["c"]++;
//				frog_count++;
//			}
//					  break;
//			case 'r': {
//				// Decrement one with "c" and increment with "cr", if "c" does not exist return -1
//				if (sub_string_freq["c"] <= 0) {
//					return -1;
//				}
//				sub_string_freq["c"]--;
//				sub_string_freq["cr"]++;
//			}
//					  break;
//			case 'o': {
//				// Decrement one with "cr" and increment with "cro", if "cr" does not exist return -1
//				if (sub_string_freq["cr"] <= 0) {
//					return -1;
//				}
//				sub_string_freq["cr"]--;
//				sub_string_freq["cro"]++;
//			}
//					  break;
//			case 'a': {
//				// Decrement one with "cro" and increment with "croa", if "cro" does not exist return -1
//				if (sub_string_freq["cro"] <= 0) {
//					return -1;
//				}
//				sub_string_freq["cro"]--;
//				sub_string_freq["croa"]++;
//			}
//					  break;
//			case 'k': {
//				// Decrement one with "croa" and increment with "croak", if "croa" does not exist return -1
//				if (sub_string_freq["croa"] <= 0) {
//					return -1;
//				}
//				sub_string_freq["croa"]--;
//				sub_string_freq["croak"]++;
//				number_of_frogs = frog_count > number_of_frogs ? frog_count : number_of_frogs;
//				frog_count--;
//			}
//					  break;
//			default:
//				return -1;
//
//			}
//		}
//
//
//		return 0 == frog_count ? number_of_frogs : -1;
//	}
//};
//
//int main() {
//
//	Solution s;
//	{
//		std::string input_string = "croakcroak";
//		std::cout << s.minNumberOfFrogs(input_string) << std::endl;
//	}
//
//	{
//		std::string input_string = "crcoakroak";
//		std::cout << s.minNumberOfFrogs(input_string) << std::endl;
//	}
//
//	{
//		std::string input_string = "croakcrook";
//		std::cout << s.minNumberOfFrogs(input_string) << std::endl;
//	}
//
//
//	{
//		std::string input_string = "croakcroa";
//		std::cout << s.minNumberOfFrogs(input_string) << std::endl;
//	}
//}