////https://leetcode.com/problems/redundant-connection/
//
//#include <vector>
//
//class Solution {
//	int find_parent(int node_index) const {
//		if (parent_[node_index] == -1) {
//			return node_index;
//		}
//		return find_parent(parent_[node_index]);
//	}
//
//	void union_parent(int parent_a, int parent_b) {
//		int a_parent = find_parent(parent_a);
//		int b_parent = find_parent(parent_b);
//
//		if (a_parent != b_parent) {
//			parent_[a_parent] = b_parent;
//		}
//	}
//
//	std::vector<int> parent_;
//
//public:
//	std::vector<int> findRedundantConnection(const std::vector<std::vector<int>>& edges) {
//		parent_.resize(edges.size(), -1);
//
//		std::vector<int> redundant_edge;
//		for (auto& edge : edges) {
//			int parent_a = find_parent(edge[0] - 1);
//			int parent_b = find_parent(edge[1] - 1);
//
//			if (parent_a == parent_b) {
//				// Cycle is introduced after adding this edge
//				redundant_edge = edge;
//				break;
//			}
//
//			union_parent(parent_a, parent_b);
//		}
//
//
//		return redundant_edge;
//	}
//};
//
//
//
//int main()
//{
//	Solution s;
//	s.findRedundantConnection({ {1, 2}, { 1, 3 }, { 2, 3 }});
//}
