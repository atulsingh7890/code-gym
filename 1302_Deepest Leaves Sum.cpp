//// https://leetcode.com/problems/deepest-leaves-sum/
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//    int depth(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        return std::max(1 + depth(root->left), 1 + depth(root->right));
//    }
//
//    int findSumAtDepth(TreeNode* root, int depth) {
//
//        if (root == nullptr) {
//            return 0;
//        }
//
//
//        if (root && depth == 1) {
//            return root->val;
//        }
//
//        if (root && depth < 0) {
//            return 0;
//        }
//
//
//        return findSumAtDepth(root->left, depth - 1) + findSumAtDepth(root->right, depth - 1);
//
//    }
//
//public:
//    int deepestLeavesSum(TreeNode* root) {
//
//        int max_depth = depth(root);
//
//        return findSumAtDepth(root, max_depth);
//
//    }
//};