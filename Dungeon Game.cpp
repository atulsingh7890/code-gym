//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <cassert>
//#include <cstdlib>
//
//class Solution {
//	int target_row = 0;
//	int target_col = 0;
//
//	using Cell = struct { int row; int col; };
//
//
//	auto inline static CellHash = [](const Cell& x) {  return std::hash<int>()(x.row) ^ std::hash<int>()(x.col);  };
//
//	auto inline static CellEqual = [](const Cell& lhs, const Cell& rhs) { return lhs.row == rhs.row && lhs.col == rhs.col; };
//
//	using CustomMap = std::unordered_map<Cell, int, decltype(CellHash), decltype(CellEqual)>;
//
//
//	int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon, int r, int c, CustomMap & cache) {
//		if (r == target_row && c == target_col) {
//			return std::max(1, 1 - dungeon[target_row][target_col]);
//		}
//
//		if (cache.find({ r,c }) != cache.end()) {
//			return cache[{r, c}];
//		}
//
//		int hp_required_to_reach_target = std::numeric_limits<int>::max();
//
//		if (r == target_row && c < target_col) {
//			hp_required_to_reach_target = std::min(hp_required_to_reach_target, calculateMinimumHP(dungeon, r, c + 1, cache));
//		}
//		else if (r < target_row && c == target_col) {
//			hp_required_to_reach_target = std::min(hp_required_to_reach_target, calculateMinimumHP(dungeon, r + 1, c, cache));
//		}
//		else {
//			
//
//			hp_required_to_reach_target = std::min({
//				hp_required_to_reach_target, 
//				calculateMinimumHP(dungeon, r + 1, c, cache),
//				calculateMinimumHP(dungeon, r, c + 1, cache) });
//		}
//		
//		cache[{r, c}] = std::max(1, hp_required_to_reach_target - dungeon[r][c]);
//
//		return cache[{r, c}];
//	}
//public:
//	int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
//		if (dungeon.size() == 0) {
//			return 0;
//		}
//
//		//target_row = dungeon.size() - 1;
//		//target_col = dungeon[0].size() - 1;
//		//CustomMap already_processed_cells_(10, CellHash, CellEqual);
//		//return calculateMinimumHP(dungeon, 0, 0, already_processed_cells_);
//
//		target_row = dungeon.size();
//		target_col = dungeon[0].size();
//
//
//	
//		std::vector<std::vector<int>> dp(target_row + 1, std::vector<int>(target_col + 1, std::numeric_limits<int>::max()));
//		dp[target_row][target_col - 1] = 1;
//		dp[target_row - 1][target_col] = 1;
//		for (int i = target_row - 1; i >= 0; i--) {
//			for (int j = target_col - 1; j >= 0; j--) {
//				dp[i][j] = std::min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
//				if (dp[i][j] <= 0) {
//					dp[i][j] = 1;
//				}
//			}
//		}
//		return dp[0][0];
//	}
//};
//
//
//int main() {
//	std::vector<std::vector<int>> dungeon{ {-2, -3, 3},{-5, -10, 1},{10, 30, -5}, };
//	Solution s;
//	assert(7 == s.calculateMinimumHP(dungeon));
//}