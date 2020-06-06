//#include <iostream>
//#include <utility>
//
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//	using IntPair = std::pair<int, int>;
//	using ResultIntPair = std::pair<bool, IntPair>;
//
//	ResultIntPair findDepthAlngWithParent(TreeNode *root, int value) {
//
//		if (root == nullptr) {
//			return { false, {-1, -1} };
//		}
//
//		if (root->val == value) {
//			return { true, {1,-1} };
//		}
//
//		ResultIntPair left_result = findDepthAlngWithParent(root->left, value);
//		ResultIntPair right_result = findDepthAlngWithParent(root->right, value);
//
//		ResultIntPair result{ false, {-1,-1} };
//		if (left_result.first) {
//			IntPair result_int_pair{ 1 + left_result.second.first, left_result.second.second };
//			result = std::pair<bool, IntPair>(true, result_int_pair);
//			if (left_result.second.second == -1) {
//				result.second.second = root->val;
//			}
//		}
//		else if (right_result.first) {
//			IntPair result_int_pair{ 1 + right_result.second.first, right_result.second.second };
//			result = std::pair<bool, IntPair>(true, result_int_pair);
//			if (right_result.second.second == -1) {
//				result.second.second = root->val;
//			}
//		}
//
//		return result;
//	}
//public:
//	bool isCousins(TreeNode* root, int x, int y) {
//		ResultIntPair x_search_result = findDepthAlngWithParent(root, 2);
//		ResultIntPair y_search_result = findDepthAlngWithParent(root, y);
//
//		bool result = false;
//		if ((x_search_result.first == y_search_result.first)
//			&& (x_search_result.second.first == y_search_result.second.first)
//			&& (x_search_result.second.second != y_search_result.second.second)) {
//			result = true;
//		}
//
//		return result;
//	}
//};
//
//int main()
//{
//	Solution s;
//	TreeNode *root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->right = new TreeNode(4);
//	root->right->right = new TreeNode(5);
//
//	std::cout << s.isCousins(root, 5, 4);
//}