//#include <string>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <cassert>
//
//class Solution {
//public:
//	std::string frequencySortWithMap(std::string s) {
//
//		std::unordered_map<char, int> frequency;
//
//		for (auto & ch : s) {
//			frequency[ch]++;
//		}
//
//		auto MySortLambda = [&](const char &a, const char &b) {
//			// As Map is build from these character 
//			// Existence check is not requried here
//			//return frequency[a] > frequency[b] || a < b;
//			if (frequency[a] > frequency[b])
//				return true;
//			else if(frequency[a] == frequency[b]){
//				return a < b;
//			}
//			else {
//				return false;
//			}
//		};
//
//		std::sort(s.begin(), s.end(), MySortLambda);
//
//		return s;
//	}
//};
//
//int main() {
//	
//}