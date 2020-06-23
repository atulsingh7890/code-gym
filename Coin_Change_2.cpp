////https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/
//
//#include <vector>
//
//class Solution {
//	
//	using IntVector = std::vector<int>;	
//	
//	int change_dp(int target_amout, const std::vector<int>& coins) {
//		IntVector dp_row(target_amout + 1, 0);
//		dp_row[0] = 1;
//		for(int i = 0; i < coins.size(); ++i) {
//			for(int j = coins[i]; j <= target_amout; ++j) {
//				dp_row[j] += dp_row[j - coins[i]];
//			}
//		}
//
//		return dp_row[target_amout];
//	}
//
//
//	int change_recursive(int target_amount , const std::vector<int>& coins, int current_coin) {
//		
//		if (target_amount < 0) {
//			return 0;
//		}
//
//		if (target_amount == 0) {
//			return 1;
//		}
//
//		if (target_amount > 0 && current_coin == coins.size())
//			return 0;
//
//		int including_current_coin = change_recursive(target_amount - coins[current_coin], coins, current_coin);
//
//		int excluding_current_coin = change_recursive(target_amount, coins, current_coin + 1);
//
//		return including_current_coin + excluding_current_coin;
//
//	}
//public:
//	int change(int amount, const std::vector<int>& coins) {		
//		//return change_recursive(amount, coins, 0);
//		return change_dp(amount, coins);
//	}
//};
//
//int main() {
//	Solution s;
//	s.change(5, { 1,2,5 });
//}