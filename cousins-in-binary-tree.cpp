//https://leetcode.com/problems/cousins-in-binary-tree/
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
    struct Result {
        TreeNode *parent;
        int height;
    };
    Result* findNode(TreeNode* root,TreeNode *parent, int height, int x) {
        if(root == nullptr)
            return nullptr;
        
        Result* result = nullptr;
        if(root->val == x) {
            return new Result{parent, height};
        } else {
            result = findNode(root->left, root, height + 1, x);
            if(result == nullptr) {
                result = findNode(root->right, root, height + 1, x);
            }
        }
        return result;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        Result *xresult = findNode(root, nullptr, 0, x);
        Result *yresult = findNode(root, nullptr, 0, y);
        
        if(xresult && yresult && xresult->height == yresult->height && xresult->parent != yresult->parent){
            return true;
        }
        return false;
        
        delete xresult;
        delete yresult;
    }
};
