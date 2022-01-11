/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int accumulatedValue = 0) {
        if(root == nullptr) {
            return 0;
        }
        
        if(root->left == nullptr && root->right ==nullptr) {
            return root->val + (accumulatedValue << 1);
        } else {
            return sumRootToLeaf(root->left, root->val + (accumulatedValue << 1)) + sumRootToLeaf(root->right, root->val + (accumulatedValue << 1));
        }    
    }
};
