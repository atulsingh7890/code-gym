////https://www.codechef.com/JUNE20B/problems/XYSTR
//
//#include <iostream>
//#include <string>
//
//int main() {
//	int testcases = 0;
//	std::cin >> testcases;
//	while (testcases--) {
//		std::string chars;
//		std::cin >> chars;
//		char prev_char;
//		prev_char = chars[0];
//
//		int pairs = 0;
//		int i = 1;
//		while (i < chars.size()) {
//			char current_char = chars[i];
//			if (prev_char != '0') {
//				if (prev_char == 'x' && current_char == 'y') {
//					pairs++;
//					prev_char = '0';
//				}
//				else if (prev_char == 'y' && current_char == 'x') {
//					pairs++;
//					prev_char = '0';
//				}
//				else {
//					prev_char = current_char;
//				}
//			}
//			else {
//				prev_char = current_char;
//			}
//
//			i++;
//		}
//		std::cout << pairs << std::endl;
//	}
//}