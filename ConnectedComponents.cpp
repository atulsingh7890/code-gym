//#include <iostream>
//#include <vector>
//#include <stack>
//#include <utility>
//#include <cassert>
//
//class Solution {
//public:
//	int numIslands(std::vector<std::vector<char>>& grid) {
//
//		if (grid.size() == 0) {
//			return 0;
//		}
//
//		int height = grid.size();
//		int width = grid[0].size();
//		int island_count = 0;
//
//		auto isValid = [=](int r, int c) {return r >= 0 && r < height && c >= 0 && c < width; };
//		std::vector<std::pair<int, int>> neighbours({ {-1,0}, {1,0}, {0,-1}, {0,1} });
//
//		std::vector<std::vector<bool>> visited_places(height);
//		for (int i = 0; i < grid.size(); ++i) {
//			visited_places[i].resize(width, false);
//		}
//
//		std::stack<std::pair<int, int>> nodes_to_process;
//
//		for (int i = 0; i < height; ++i) {
//			for (int j = 0; j < width; ++j) {
//				if (grid[i][j] == '1' && false == visited_places[i][j]) {
//					island_count++;
//					nodes_to_process.push(std::make_pair(i, j));					
//
//					while (!nodes_to_process.empty()) {
//						std::pair<int, int> current_node = nodes_to_process.top();
//						nodes_to_process.pop();
//						int current_r = current_node.first;
//						int current_c = current_node.second;
//
//						visited_places[current_r][current_c] = true;						
//
//						for (auto neighbour : neighbours) {
//							int neighbour_r = neighbour.first + current_r;
//							int neighbour_c = neighbour.second + current_c;
//							if (isValid(neighbour_r, neighbour_c) &&
//								(grid[neighbour_r][neighbour_c] == '1') &&
//								!visited_places[neighbour_r][neighbour_c]) {
//								nodes_to_process.push(std::make_pair(neighbour_r, neighbour_c));
//							}
//						}
//					}
//				}
//			}
//		}
//		
//		return island_count;
//
//	}
//};
//
//
//
//int main() {
//
//	std::vector<std::pair<std::vector<std::vector<char>>, int>> testcases = { {{}, 0},
//	{{{'1','0'}}, 1},
//	{{{'1','0'},
//	  {'0','1'}}, 2},
//	{{{'1','1'},
//	  {'0','1'}}, 1},
//	{{{'1','1'},
//	  {'1','1'}}, 1},
//	{{{'1','1','1'},
//	  {'0','1','0'},
//	  {'1','1','1'}}, 1}, };
//
//	Solution s;
//	for (auto & test : testcases) {
//		assert(test.second == s.numIslands(test.first));
//	}
//}