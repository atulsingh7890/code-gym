//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3797/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TLE
//         auto first_node_path = findPathOfNode(root, p, {});
//         auto second_node_path = findPathOfNode(root, q, {});
//         TreeNode *lca = nullptr;
//         int index = 0;
//         while(index < first_node_path.second.size() && 
//               index < second_node_path.second.size() &&
//               first_node_path.second[index] == second_node_path.second[index]) {
//             lca = first_node_path.second[index];
//             index++;
//         }
//         return lca;
        
        
        TreeNode *result = nullptr;
        lca(root, p, q, result);
        return result;
    }
private:
    
    
    bool lca(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode * & result) {
        if(root == nullptr) {
            return false;
        }
        
        // status from left subtree
        int left_status = lca(root->left, p, q, result) ? 1 : 0;
        
        // right status from right subtree
        int right_status = lca(root->right, p, q, result) ? 1 : 0;
        
        int current_node_status = ( root == p || root == q ) ? 1 : 0;
        
        if(left_status + right_status + current_node_status >= 2) {
            result = root;
        }
        
        return (left_status + right_status + current_node_status) > 0;
    }
    
    
    
    std::pair<bool, std::vector<TreeNode*>> findPathOfNode(TreeNode *root, TreeNode *p, std::vector<TreeNode*> pathTillNow) {
        
        if(root == nullptr) {
            return {false, {}};
        }

        pathTillNow.push_back(root);
        
        if(p == root) {
            return {true,pathTillNow};
        }
        
        
        auto left_status = findPathOfNode(root->left, p, pathTillNow);
        if(left_status.first) {
            return left_status;
        }
        
        auto right_status = findPathOfNode(root->right, p, pathTillNow);
        if(right_status.first) {
            return right_status;
        }
        
        return {false, {}};
        
    }
    
};
