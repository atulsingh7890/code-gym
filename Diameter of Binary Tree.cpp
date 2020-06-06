//#include <iostream>
//#include <algorithm>
//#include <cassert>
//
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
//
//
//class Solution {
//public:
//
//	//int height(TreeNode *root) {
//	//	if (root == nullptr) {
//	//		return 0;
//	//	}
//	//	return 1 + std::max(height(root->left), height(root->right));
//	//}
//
//	int diameterOfBinaryTreeWithHeight(TreeNode* root, int &height) {
//		if (root == nullptr) {
//			height = 0;
//			return 0;
//		}
//
//		int left_height = 0;
//		int right_height = 0;
//		int left_diameter = diameterOfBinaryTreeWithHeight(root->left, left_height);
//		int right_diameter = diameterOfBinaryTreeWithHeight(root->right, right_height);
//
//		height = 1 + std::max(left_height, right_height);
//
//		return std::max(left_height + right_height, std::max(left_diameter, right_diameter));
//	}
//
//	int diameterOfBinaryTree(TreeNode* root) {
//
//		int height_ = 0;
//		return diameterOfBinaryTreeWithHeight(root, height_);
//
//		//if (root == nullptr) {
//		//	return 0;
//		//}
//
//		//int left_diameter = diameterOfBinaryTree(root->left);
//		//int right_diameter = diameterOfBinaryTree(root->right);
//
//		//int left_height = height(root->left);
//		//int right_height = height(root->right);
//
//		//return std::max(left_height + right_height, std::max(left_diameter, right_diameter));
//	}
//};
//
//
//int main() {
//	
//	{
//		// Test case 1 with only 1 Node , Expected answer should be zero
//		TreeNode *root = new TreeNode(1);
//		Solution s;
//		int diameter = s.diameterOfBinaryTree(root);
//		assert(0 == diameter);
//		std::cout << diameter << std::endl;
//
//		//Delete the tree to avoid any memory leaks
//	}
//
//	{
//		TreeNode *root = new TreeNode(1);
//		root->left = new TreeNode(2);
//		root->right = new TreeNode(3);
//		Solution s;
//		int diameter = s.diameterOfBinaryTree(root);
//		assert(2 == diameter);
//		std::cout << diameter << std::endl;
//
//		//Delete the tree to avoid any memory leaks
//	}
//
//
//	{
//		// Test case 2 with only 5 Nodes , Expected answer should be 3
//		TreeNode *root = new TreeNode(1);
//		root->left = new TreeNode(2);
//		root->right = new TreeNode(3);
//		root->left->left = new TreeNode(4);
//		root->left->right = new TreeNode(5);
//		Solution s;
//		int diameter = s.diameterOfBinaryTree(root);
//		assert(3 == diameter);
//		std::cout << diameter << std::endl;
//
//		//Delete the tree to avoid any memory leaks
//	}
//
//
//	{
//		// Test case 2 with only 5 Nodes , Expected answer should be 3
//		TreeNode *root = new TreeNode(1);
//		root->left = new TreeNode(2);
//		root->left->left = new TreeNode(3);
//		root->left->left->left = new TreeNode(4);
//		root->left->left->right = new TreeNode(5);
//		root->left->left->right->right = new TreeNode(6);
//		root->left->left->right->right->right = new TreeNode(7);
//		root->left->left->right->right->right->right = new TreeNode(8);
//		Solution s;
//		int diameter = s.diameterOfBinaryTree(root);
//		assert(6 == diameter);
//		std::cout << diameter << std::endl;
//
//		//Delete the tree to avoid any memory leaks
//	}
//
//}