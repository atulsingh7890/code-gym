//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <map>
//#include <algorithm>
//#include <cassert>
//
//class Solution {
//	using CharFrequencyMap = std::unordered_map<char, int>;
//
//	bool compare_map(const CharFrequencyMap & a_map, const CharFrequencyMap & b_map) {
//		for (auto it_a = a_map.begin(); it_a != a_map.end(); ++it_a) {
//			auto it_b = b_map.find(it_a->first);
//			if (it_b == b_map.end()) {
//				return false;
//			}
//
//			if (it_a->second != it_b->second) {
//				return false;
//			}
//		}
//
//		return true;		
//	}
//
//public:
//	std::vector<int> findAnagrams(std::string s, std::string p) {
//	
//
//		std::vector<int> vector_indices;
//		bool is_window_initialized = false;
//		CharFrequencyMap anagram_pattern;
//		CharFrequencyMap  moving_pattern;
//		for (int i = 0; i < s.size() ; ++i) {
//			if ( i < p.size()) {
//				moving_pattern[s[i]]++;
//				anagram_pattern[p[i]]++;
//			}
//			else {				
//
//				// Compare the maps till now
//				if (compare_map(moving_pattern, anagram_pattern)) {
//					vector_indices.push_back(i - p.size());
//				}
//
//				// Remove the last character and insert the current character ,
//				//while removing also check if it needs deletion or not
//				char outgoing_character = s[i - p.size()];
//				char incoming_character = s[i];
//
//				auto it_outgoing_character = moving_pattern.find(outgoing_character);
//				if (it_outgoing_character->second == 1) {
//					moving_pattern.erase(it_outgoing_character);
//				}
//				else {
//					(it_outgoing_character->second)--;
//				}
//
//				moving_pattern[incoming_character]++;
//
//				
//			}			
//		}
//
//		// Compare for the last character maps till now
//		if (compare_map(moving_pattern, anagram_pattern) && s.size() >= p.size()) {
//			vector_indices.push_back(s.size() - p.size());
//		}
//		
//		return vector_indices;
//	}
//};
//
//
//int main() {
//	std::map< std::pair<std::string, std::string>, std::vector<int>> testcases{
//		{{"cbaebabacd", "abc"}, {0, 6}},
//		{{"abab", "ab"}, {0, 1, 2}},
//		{{"ababa", "a"}, {0, 2, 4}},
//		{{"", "a"}, {}},
//	};
//
//	for (auto & testcase : testcases) {
//		Solution s;
//		std::vector<int> result = s.findAnagrams(testcase.first.first, testcase.first.second);
//
//		assert(std::equal(testcase.second.begin(), testcase.second.end(), result.begin()));
//	}
//}