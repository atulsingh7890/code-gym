//#include <iostream>
//#include <vector>
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//	
//};
//
//class Solution {
//public:
//
//	TreeNode * buildPreOrder(std::vector<int> &preorder, int start, int end) {
//
//		if (start > end) {
//			return nullptr;
//		}
//
//		// Find the First index k where preorder[k] is greater than preorder[start]
//		if (start == end) {
//			return new TreeNode(preorder[start]);
//		}
//
//		int k = start + 1;
//		for (; k <= end; ++k) {
//			if (preorder[start] < preorder[k]) {
//				break;
//			}
//		}
//
//		TreeNode *current_root = new TreeNode(preorder[start]);
//		TreeNode *left_node = buildPreOrder(preorder, start + 1, k - 1);
//		TreeNode *right_node = buildPreOrder(preorder, k, end);
//
//		current_root->left = left_node;
//		current_root->right = right_node;
//
//		return current_root;
//	}
//
//	TreeNode* bstFromPreorder(std::vector<int>& preorder) {
//		
//		return buildPreOrder(preorder, 0, preorder.size() - 1);
//	}
//};
//
//int main() {
//
//
//	{
//		std::vector<int> input = { 8, 5, 1, 7, 10, 12 };
//		Solution s;
//		//TreeNode * root =  s.bstFromPreorder(input);
//	}
//
//	{
//		std::vector<int> input = { 1, 0, 2 };
//		Solution s;
//		TreeNode * root = s.bstFromPreorder(input);
//	}
//
//	{
//		std::vector<int> input = { 0, 2 };
//		Solution s;
//		TreeNode * root = s.bstFromPreorder(input);
//	}
//
//}