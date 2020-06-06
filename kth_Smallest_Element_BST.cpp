//#include <cassert>
//
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
//class Solution {
//	struct ResultStatus {
//		bool result_status_;
//		int k_th_element;
//	};
//	void kthSmallest(TreeNode *root, int & current_index, int target_index, ResultStatus & result_status) {
//
//		if (root->left && !result_status.result_status_ ) {
//			kthSmallest(root->left, current_index, target_index, result_status);
//		}
//
//		current_index++;
//		if (current_index == target_index) {
//			result_status.k_th_element = root->val;
//			result_status.result_status_ = true;
//			return;
//		}
//
//		if (root->right && !result_status.result_status_) {
//			kthSmallest(root->right, current_index, target_index, result_status);
//		}
//
//		return;
//	}
//public:
//	int kthSmallest(TreeNode* root, int  k) {
//		ResultStatus result_status{false, -1};
//		int current_index = 0;
//		kthSmallest(root, current_index, k, result_status);
//		return result_status.k_th_element;
//	}
//};
//
//
//int main() {
//	{
//		TreeNode *root = new TreeNode(3);
//		root->left = new TreeNode(1);
//		root->left->right = new TreeNode(2);
//		root->right = new TreeNode(4);
//		Solution s;
//		assert(1 == s.kthSmallest(root, 1));
//		assert(2 == s.kthSmallest(root, 2));
//		assert(3 == s.kthSmallest(root, 3));
//		assert(4 == s.kthSmallest(root, 4));
//	}
//
//	{
//		TreeNode *root = new TreeNode(5);
//		root->left = new TreeNode(3);
//		root->right = new TreeNode(6);
//		root->left->left = new TreeNode(2);
//		root->left->right = new TreeNode(4);
//		root->left->left->left = new TreeNode(1);
//		Solution s;
//		assert(1 == s.kthSmallest(root, 1));
//		assert(2 == s.kthSmallest(root, 2));
//		assert(3 == s.kthSmallest(root, 3));
//		assert(4 == s.kthSmallest(root, 4));
//		assert(5 == s.kthSmallest(root, 5));
//		assert(6 == s.kthSmallest(root, 6));
//	}
//}