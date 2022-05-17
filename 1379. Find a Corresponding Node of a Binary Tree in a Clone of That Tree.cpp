/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == nullptr or cloned == nullptr or target == nullptr) {
            return nullptr;
        }
        
        if(original == target) {
            return cloned;
        }
        
        TreeNode*  resultFromLeft = getTargetCopy(original->left, cloned->left, target);
        
        if(resultFromLeft == nullptr) {
            TreeNode * resultFromRight = getTargetCopy(original->right, cloned->right, target);
            if(resultFromRight != nullptr) {
                return resultFromRight;
            }
        } else {
            return resultFromLeft;
        }
        
        return nullptr;
        
    }
};
