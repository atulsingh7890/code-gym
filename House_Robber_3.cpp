//https://leetcode.com/problems/house-robber-iii/
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
    int rob(TreeNode* root) {
        std::map<TreeNode*,int> cache;
        return robHelper(root, cache);
    }
private:
    int robHelper(TreeNode *root, std::map<TreeNode*, int> & cache) {
        
        if(root == nullptr)
            return 0;
        
        
        auto it = cache.find(root);
        if(it != cache.end())
            return cache[root];
        
        //rob current node
        int rob_current = root->val ;
        if(root->left){
            rob_current += robHelper(root->left->left, cache);
            rob_current += robHelper(root->left->right, cache);
        }
        if(root->right) {
            rob_current += robHelper(root->right->left, cache);
            rob_current += robHelper(root->right->right, cache);
        }
        
        
        //dont run current node
        int dont_rob_current_node = 0;
        if(root->left) {
            dont_rob_current_node +=  robHelper(root->left, cache);
        }
        if(root->right) {
            dont_rob_current_node +=  robHelper(root->right, cache);
        }
        
        int result = std::max(rob_current, dont_rob_current_node);
        cache[root] = result;
        return result;
        
    }
};
