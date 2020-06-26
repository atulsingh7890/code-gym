//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/

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
    void sumNumbers(TreeNode *root, int number_till_now, int  & sum_till_now) {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr) {
            number_till_now = number_till_now * 10 + root->val;
            sum_till_now += number_till_now;
            return;
        }
        
        number_till_now = number_till_now * 10 + root->val;
        
        sumNumbers(root->left, number_till_now, sum_till_now);
        sumNumbers(root->right, number_till_now, sum_till_now);        
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int result = 0;
        sumNumbers(root, 0, result);
        return result;
    }
};
