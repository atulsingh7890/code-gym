//https://leetcode.com/problems/path-sum-iii/

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
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;  // default value
        return pathSumHelper(root, 0, targetSum, prefixSum);
    }
    
    int pathSumHelper(TreeNode* root,int currentSum, int targetSum, std::unordered_map<int,int> & preSum) {
        if(root == nullptr)
            return 0;
        
        currentSum += root->val;
        
        int remaning_difference = currentSum - targetSum;
        
        auto it = preSum.find(remaning_difference);
        
        int sum_windows_till_this_point = it == preSum.end() ? 0 : it->second;
        
        preSum[currentSum] = preSum[currentSum] + 1;
        
        sum_windows_till_this_point += pathSumHelper(root->left, currentSum, targetSum, preSum)
                                     + pathSumHelper(root->right, currentSum, targetSum, preSum);
        
        preSum[currentSum] = preSum[currentSum] - 1;
        
        return sum_windows_till_this_point;
    }
};
