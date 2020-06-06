//#include <iostream>
//#include <vector>
//#include <cassert>
//
///**
// * Definition for a binary tree node.
// */
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
//
//	bool IsChildNode(TreeNode *root) {
//		return root && !root->left && !root->right;
//	}
//
//	bool isValidSequence(TreeNode* root, std::vector<int>& arr, int current_index) {
//
//		if (root == nullptr && current_index < arr.size()) {
//			return false;
//		}
//
//		if (IsChildNode(root)) {
//			if ((current_index == (arr.size() - 1))) {
//				if (root->val == arr[current_index])
//					return true;
//				else
//					return false;
//			}
//			else
//			{
//				return false;
//			}
//		}
//				
//		if ( current_index < arr.size() && root->val == arr[current_index]) {
//			return isValidSequence(root->left, arr, current_index + 1)
//				|| isValidSequence(root->right, arr, current_index + 1);
//		}
//		
//		return false;	
//
//	}
//public:
//	bool isValidSequence(TreeNode* root, std::vector<int>& arr) {	
//		return isValidSequence(root, arr, 0);
//	}
//};
//
//int main() {
//	{
//		TreeNode *root = new TreeNode(0);
//		root->left = new TreeNode(1);
//		root->right = new TreeNode(0);
//		root->left->left = new TreeNode(0);
//		root->left->right = new TreeNode(1);
//		root->left->left->right = new TreeNode(1);
//		root->left->right->left = new TreeNode(0);
//		root->left->right->right = new TreeNode(0);
//		root->right->left = new TreeNode(0);
//
//		{
//			std::vector<int> input = { 0, 1, 0, 1 };
//			Solution s;
//			assert(true == s.isValidSequence(root, input));
//		}
//
//		{
//			std::vector<int> input = { 0, 1, 1, 0 };
//			Solution s;
//			assert(true == s.isValidSequence(root, input));
//		}
//
//		{
//			std::vector<int> input = { 0, 0, 0 };
//			Solution s;
//			assert(true == s.isValidSequence(root, input));
//		}
//
//		{
//			std::vector<int> input = { 0, 0 };
//			Solution s;
//			s.isValidSequence(root, input);
//			assert(false == s.isValidSequence(root, input));
//		}
//
//		{
//			std::vector<int> input = { 0, 1, 0 };
//			Solution s;
//			s.isValidSequence(root, input);
//			assert(false == s.isValidSequence(root, input));
//		}
//	}
//
//	{
//		TreeNode *root = new TreeNode(0);
//
//		{
//			std::vector<int> input = { 0, 1, 0, 1 };
//			Solution s;
//			assert(false == s.isValidSequence(root, input));
//		}
//
//		{
//			std::vector<int> input = { 0 };
//			Solution s;
//			assert(true == s.isValidSequence(root, input));
//		}
//		{
//			std::vector<int> input = { 1 };
//			Solution s;
//			assert(false == s.isValidSequence(root, input));
//		}
//		{
//			std::vector<int> input = { };
//			Solution s;
//			assert(false == s.isValidSequence(root, input));
//		}
//
//	}
//
//	{
//		TreeNode *root = nullptr;
//
//		{
//			std::vector<int> input = { 0, 1, 0, 1 };
//			Solution s;
//			assert(false == s.isValidSequence(root, input));
//		}
//
//		{
//			std::vector<int> input = { 0 };
//			Solution s;
//			assert(false == s.isValidSequence(root, input));
//		}
//		{
//			std::vector<int> input = { 1 };
//			Solution s;
//			assert(false == s.isValidSequence(root, input));
//		}
//		{
//			std::vector<int> input = { };
//			Solution s;
//			assert(false == s.isValidSequence(root, input));
//		}
//
//	}
//}