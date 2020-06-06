//#include <string>
//#include <vector>
//#include <algorithm>
//
//class Solution {
//public:
//	int minDistanceDP(std::string word1, std::string word2) {
//
//		//Whole dp matrix is not required, only two rows are fine
//		std::vector<std::vector<int>> dp(2, std::vector<int>(word1.size(), 0));
//
//		int current_row_in_dp = 0;
//		for (int i = 0; i < word2.size(); ++i) {
//			for (int j = 0; j < word1.size(); ++j) {
//				int north_west =  i > 0 && j > 0 ? dp[1 - current_row_in_dp][j-1] : std::max(i,j);
//				int north = i > 0 ? dp[1 - current_row_in_dp][j] : j + 1;
//				int west = j > 0 ? dp[current_row_in_dp][j - 1] : i + 1;
//				if (word2[i] == word1[j]) {
//					dp[current_row_in_dp][j] = north_west;
//				}
//				else {
//					dp[current_row_in_dp][j] = 1 + std::min({ north_west, north, west });
//				}
//			}	
//			current_row_in_dp = 1 - current_row_in_dp;
//		}
//		return dp[1 - current_row_in_dp][word1.size()-1];
//	}
//	int minDistance(std::string word1, std::string word2, int word1_index = 0, int word2_index = 0) {
//				
//		if (word1.size() == word1_index || word2.size() == word2_index) {
//			return std::max(word1.size() - word1_index, word2.size() - word2_index);
//		}
//
//		return minDistanceDP(word1, word2);
//
//		// Recursive Implementation
//		/*if (word1[word1_index] == word2[word2_index]) {
//			return minDistance(word1, word2, word1_index + 1, word2_index + 1);
//		}
//		else {
//			int distance_after_making_same = 1 + minDistance(word1, word2, word1_index + 1, word2_index + 1);
//			int distance_after_inserting_the_same_character = 1 + minDistance(word1, word2, word1_index, word2_index + 1);
//			int distance_after_deleting_the_mismatch_character = 1 + minDistance(word1, word2, word1_index + 1, word2_index);
//			return std::min({
//					distance_after_making_same,
//					distance_after_inserting_the_same_character,
//					distance_after_deleting_the_mismatch_character
//				});
//		}
//		
//		return 0;*/
//
//	}
//};
//
//
//int main() {
//	Solution s;
//	//int answer = s.minDistance("horse", "ros");
//	int answer = s.minDistance("plasma", "altruism");
//}