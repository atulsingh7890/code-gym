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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q[2];
        int current_queue = 0;
        
        q[current_queue].push(root);
        
        while(!q[current_queue].empty()  ||  !q[1 - current_queue].empty()) {
            std::vector<int> level;
            while(!q[current_queue].empty()) {
                TreeNode * current_node = q[current_queue].front();
                q[current_queue].pop();
                
                level.push_back(current_node->val);
                
                if(current_node->left) {
                    q[1-current_queue].push(current_node->left);
                }
                
                if(current_node->right) {
                    q[1-current_queue].push(current_node->right);
                }                  
            }
            result.push_back(level);
            current_queue = 1 - current_queue;
        }
        
        return result;
    }
};
