////https://leetcode.com/problems/stone-game/
//
//#include <algorithm>
//#include <vector>
//
//class Solution {
//public:
//	bool stoneGame(std::vector<int>& piles) {
//		return stoneGame(piles, GameParameters{ 0, (int)piles.size() - 1, 0, 0 });
//	}
//private:
//	struct GameParameters {
//		int start_index;
//		int end_index;
//		int alex_score;
//		int lee_score;
//	};
//	bool stoneGame(std::vector<int>& piles, GameParameters game_parameters) {
//		
//		if (game_parameters.end_index - game_parameters.start_index == 1) {
//			return (game_parameters.alex_score + std::max(piles[game_parameters.start_index], piles[game_parameters.end_index])
//				> game_parameters.lee_score + std::min(piles[game_parameters.start_index], piles[game_parameters.end_index]));
//		}
//		else {
//			// Score if picked the left element
//			GameParameters game_params_left_pick{
//				game_parameters.start_index + 1,
//				game_parameters.end_index - 1,
//				game_parameters.alex_score + piles[game_parameters.start_index],
//				game_parameters.lee_score + piles[game_parameters.end_index]
//			};
//			// Score if picked the right element
//			GameParameters game_params_right_pick{
//				game_parameters.start_index + 1,
//				game_parameters.end_index - 1,
//				game_parameters.alex_score + piles[game_parameters.end_index],
//				game_parameters.lee_score + piles[game_parameters.start_index]
//			};
//			return stoneGame(piles, game_params_left_pick) || stoneGame(piles, game_params_right_pick);;
//		}
//	}
//};