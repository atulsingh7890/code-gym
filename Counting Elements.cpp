//#include <iostream>
//#include <vector>
//#include <map>
//
//class Solution {
//public:
//	int countElements(std::vector<int>& arr) {
//		std::map<int, int> freq;
//		for (auto val : arr) {
//			if (freq.find(val) == freq.end()) {
//				freq[val] = 0;
//			}
//			freq[val] += 1;
//		}
//		int result = 0;
//		for (auto val : arr) {
//			std::map<int, int>::iterator it = freq.find(val + 1);
//			if (it != freq.end()) {
//				result++;
//				//freq.erase(it);
//				//freq.erase(freq.find(val));
//			}
//		}
//		return result;
//	}
//};
//
//
//int main() {
//	Solution s;
//	std::vector<int> input = { 1, 2, 3 };
//	std::cout << s.countElements(input);
//}