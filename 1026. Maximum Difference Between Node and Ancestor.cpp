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
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        return maxDiff(root, root->val, root->val);
    }
private:
    int maxDiff(TreeNode * root, int max, int min) {
        if(root == nullptr)
            return max - min;
        
        max = std::max(max, root->val);
        min = std::min(min, root->val);
        int left = maxDiff(root->left, max, min);
        int right = maxDiff(root->right, max, min);
        return std::max(left, right);
    }
};
