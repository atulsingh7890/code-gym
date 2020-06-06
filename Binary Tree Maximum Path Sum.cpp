//#include <iostream>
//#include <algorithm>
//#include <climits>
//#include <utility>
//#include <cassert>
//
//// Definition for a binary tree node.
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// 
//class Solution {
//public:
//	int maxPathSum(TreeNode* root) {
//		std::pair<int, int> result =  maxPathSumHelper(root);
//		return std::max({result.first, result.second});
//	}
//
//	std::pair<int, int> maxPathSumHelper(TreeNode* root) {
//		if (root == nullptr) {
//			return { std::numeric_limits<int>::min(), std::numeric_limits<int>::min() };
//		}
//
//
//		std::pair<int,int> left_subtree_result = maxPathSumHelper(root->left);
//		std::pair<int, int> right_subtree_result = maxPathSumHelper(root->right);
//
//		int max_path_sum_from_left_subtre = left_subtree_result.first;
//		int max_path_sum_from_right_subtree = right_subtree_result.first;
//
//		int line_with_max_sum_left = std::max(left_subtree_result.second, 0);
//		int line_with_max_sum_right = std::max(right_subtree_result.second, 0);		
//
//		return { std::max({
//				root->val,
//				root->val + line_with_max_sum_left ,
//				root->val + line_with_max_sum_right ,
//				root->val + line_with_max_sum_left + line_with_max_sum_right ,
//				max_path_sum_from_left_subtre,
//				max_path_sum_from_right_subtree,
//				}),
//				std::max({
//				root->val,
//				line_with_max_sum_left + root->val,
//				line_with_max_sum_right + root->val,
//				}) };
//
//	}
//};
//
//
//int main() {
//	{
//		TreeNode *root = new TreeNode(-10);
//		root->left = new TreeNode(9);
//		root->right = new TreeNode(20);
//		root->right->left = new TreeNode(15);
//		root->right->right = new TreeNode(7);
//		Solution s;
//		int answer = s.maxPathSum(root);
//		assert(42 == answer);		
//	}
//
//	{
//		TreeNode *root = new TreeNode(-10);		
//		Solution s;
//		int answer = s.maxPathSum(root);
//		assert(-10 == answer);
//	}
//
//	{
//		TreeNode *root = new TreeNode(1);
//		root->left = new TreeNode(-2);
//		root->right = new TreeNode(3);
//		Solution s;
//		int answer = s.maxPathSum(root);
//		assert(4 == answer);
//	}
//
//	{
//		TreeNode *root = new TreeNode(-1);
//		root->left = new TreeNode(-2);
//		root->right = new TreeNode(3);
//		Solution s;
//		int answer = s.maxPathSum(root);
//		assert(3 == answer);
//	}
//
//	{
//		TreeNode *root = new TreeNode(-2);
//		root->left = new TreeNode(6);
//		root->left->left = new TreeNode(0);
//		root->left->right = new TreeNode(-6);
//		Solution s;
//		int answer = s.maxPathSum(root);
//		assert(6 == answer);
//	}
//
//
//	{
//		TreeNode *root = new TreeNode(-1);
//		root->right = new TreeNode(9);
//		root->right->left = new TreeNode(-6);
//		root->right->right = new TreeNode(3);
//		root->right->right->right = new TreeNode(2);
//		Solution s;
//		int answer = s.maxPathSum(root);
//		assert(12 == answer);
//	}
//}