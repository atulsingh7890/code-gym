//#include <vector>
//#include <queue>
//#include <set>
//
//class Solution {
//public:
//	bool possibleBipartition(int N, const std::vector<std::vector<int>>& dislikes) {
//
//		std::vector<std::vector<int>> haters_adjacency_list(N, std::vector<int>());
//		
//		for (auto& dislike : dislikes) {
//			const int& person_a = dislike[0];
//			const int& person_b = dislike[1];
//			haters_adjacency_list[person_a - 1].push_back(person_b - 1);
//			haters_adjacency_list[person_b - 1].push_back(person_a - 1);
//		}
//
//		enum {
//			BLACKIE = 0,
//			WHITEE = 1
//		};
//
//		std::set<int> skin_color_verified;
//		for (int i = 0; i < N; ++i) {
//			skin_color_verified.insert(i);
//		}
//
//
//
//		// Now lets try to color the Graph with Only two Colors  : 0 and 1
//		std::vector<int> person_colors(N, -1);		
//
//		std::queue<int> breadth_first_queue;
//
//		bool there_is_racism = true;
//
//		while (skin_color_verified.size() > 0) {
//			
//			int current_starting_person = *(skin_color_verified.begin());
//			breadth_first_queue.push(current_starting_person);
//			person_colors[current_starting_person] = BLACKIE;			
//			skin_color_verified.erase(skin_color_verified.find(current_starting_person));
//
//			while (false == breadth_first_queue.empty()) {
//				int current_person = breadth_first_queue.front();
//				breadth_first_queue.pop();
//
//				for (auto& hater : haters_adjacency_list[current_person]) {
//					if (person_colors[hater] == person_colors[current_person]) {
//						// BLACKIE and WHITEE cannot coexist
//						there_is_racism = false;
//						break;
//					}
//					else if (person_colors[hater] == -1) {
//						person_colors[hater] = person_colors[current_person] == BLACKIE ? WHITEE : BLACKIE;
//						//person_colors[hater] = 1 - person_colors[current_person];
//						breadth_first_queue.push(hater);
//						skin_color_verified.erase(skin_color_verified.find(hater));
//					}
//				}
//
//				if (false == there_is_racism) {
//					break;
//				}
//			}
//			if (false == there_is_racism) {
//				break;
//			}
//		}		
//
//		return there_is_racism;
//	}
//};
//
//
//int main() {
//	Solution s;
//	//s.possibleBipartition(4, { {1,2}, {1,3}, {2,4} });
//	int size = 50;
//		std::vector<std::vector<int>> input{ {21, 47}, {4, 41}, {2, 41}, {36, 42}, {32, 45}, {26, 28}, {32, 44}, {5, 41}, {29, 44}, {10, 46}, {1, 6}, {7, 42}, {46, 49}, {17, 46}, {32, 35}, {11, 48}, {37, 48}, {37, 43}, {8, 41}, {16, 22}, {41, 43}, {11, 27}, {22, 44}, {22, 28}, {18, 37}, {5, 11}, {18, 46}, {22, 48}, {1, 17}, {2, 32}, {21, 37}, {7, 22}, {23, 41}, {30, 39}, {6, 41}, {10, 22}, {36, 41}, {22, 25}, {1, 12}, {2, 11}, {45, 46}, {2, 22}, {1, 38}, {47, 50}, {11, 15}, {2, 37}, {1, 43}, {30, 45}, {4, 32}, {28, 37}, {1, 21}, {23, 37}, {5, 37}, {29, 40}, {6, 42}, {3, 11}, {40, 42}, {26, 49}, {41, 50}, {13, 41}, {20, 47}, {15, 26}, {47, 49}, {5, 30}, {4, 42}, {10, 30}, {6, 29}, {20, 42}, {4, 37}, {28, 42}, {1, 16}, {8, 32}, {16, 29}, {31, 47}, {15, 47}, {1, 5}, {7, 37}, {14, 47}, {30, 48}, {1, 10}, {26, 43}, {15, 46}, {42, 45}, {18, 42}, {25, 42}, {38, 41}, {32, 39}, {6, 30}, {29, 33}, {34, 37}, {26, 38}, {3, 22}, {18, 47}, {42, 48}, {22, 49}, {26, 34}, {22, 36}, {29, 36}, {11, 25}, {41, 44}, {6, 46}, {13, 22}, {11, 16}, {10, 37}, {42, 43}, {12, 32}, {1, 48}, {26, 40}, {22, 50}, {17, 26}, {4, 22}, {11, 14}, {26, 39}, {7, 11}, {23, 26}, {1, 20}, {32, 33}, {30, 33}, {1, 25}, {2, 30}, {2, 46}, {26, 45}, {47, 48}, {5, 29}, {3, 37}, {22, 34}, {20, 22}, {9, 47}, {1, 4}, {36, 46}, {30, 49}, {1, 9}, {3, 26}, {25, 41}, {14, 29}, {1, 35}, {23, 42}, {21, 32}, {24, 46}, {3, 32}, {9, 42}, {33, 37}, {7, 30}, {29, 45}, {27, 30}, {1, 7}, {33, 42}, {17, 47}, {12, 47}, {19, 41}, {3, 42}, {24, 26}, {20, 29}, {11, 23}, {22, 40}, {9, 37}, {31, 32}, {23, 46}, {11, 38}, {27, 29}, {17, 37}, {23, 30}, {14, 42}, {28, 30}, {29, 31}, {1, 8}, {1, 36}, {42, 50}, {21, 41}, {11, 18}, {39, 41}, {32, 34}, {6, 37}, {30, 38}, {21, 46}, {16, 37}, {22, 24}, {17, 32}, {23, 29}, {3, 30}, {8, 30}, {41, 48}, {1, 39}, {8, 47}, {30, 44}, {9, 46}, {22, 45}, {7, 26}, {35, 42}, {1, 27}, {17, 30}, {20, 46}, {18, 29}, {3, 29}, {4, 30}, {3, 46} };
//
//	s.possibleBipartition(size, input);
//
//
//}