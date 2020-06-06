//#include <iostream>
//#include <vector>
//#include <map>
//#include <string>
//
//class Solution {
//public:
//
//	template <typename Map>
//	bool key_compare(Map const &lhs, Map const &rhs) {
//
//		auto pred = [](decltype(*lhs.begin()) a, decltype(a) b)
//		{ return a.first == b.first && a.second == b.second; };
//
//		return lhs.size() == rhs.size()
//			&& std::equal(lhs.begin(), lhs.end(), rhs.begin(), pred);
//	}
//
//
//	std::map<char, int> buildFreqMap(std::string &str) {
//		std::map<char, int> freqMap;
//		for (int i = 0; i < str.size(); ++i) {
//			if (freqMap.find(str[i]) == freqMap.end()) {
//				freqMap[str[i]] = 0;
//			}
//			freqMap[str[i]] += 1;
//		}
//		return freqMap;
//	}
//
//
//	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
//
//		std::map<std::string, std::map<char, int>> stringFreqMap;
//
//		std::vector<std::vector<std::string>> grouped_anagrams;
//		for (int i = 0; i < strs.size(); ++i) {
//
//			std::map<char, int> freqMap = buildFreqMap(strs[i]);
//			if (stringFreqMap.find(strs[i]) == stringFreqMap.end()) {
//				stringFreqMap[strs[i]] = freqMap;
//			}
//
//			bool anagram_found = false;
//			for (int j = 0; j < grouped_anagrams.size(); ++j) {
//				if (grouped_anagrams[j].size() >= 1) {
//					std::map<char, int> &freqMap1 = stringFreqMap[grouped_anagrams[j][0]];
//					if (key_compare(stringFreqMap[grouped_anagrams[j][0]], freqMap)) {
//						grouped_anagrams[j].push_back(strs[i]);
//						anagram_found = true;
//						break;
//					}
//				}
//			}
//
//			if (anagram_found == false) {
//				grouped_anagrams.push_back(std::vector<std::string>{strs[i]});
//			}
//		}
//		return grouped_anagrams;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	std::vector<std::string> strs{ "hos","boo","nay","deb","wow","bop","bob","brr","hey","rye","eve","elf","pup","bum","iva","lyx","yap","ugh","hem","rod","aha","nam","gap","yea","doc","pen","job","dis","max","oho","jed","lye","ram","pup","qua","ugh","mir","nap","deb","hog","let","gym","bye","lon","aft","eel","sol","jab" };
//	std::vector<std::vector<std::string>> grouped = s.groupAnagrams(strs);
//	for (int i = 0; i < grouped.size(); ++i) {
//		std::cout << "Group " << i + 1 << std::endl;
//		for (int j = 0; j < grouped[i].size(); ++j) {
//			std::cout << grouped[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//
//}