////https://leetcode.com/problems/binary-search-tree-iterator/
//
//#include <stack>
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
//class BSTIterator {
//private:
//    TreeNode* root_node_ = nullptr;
//
//    BSTIterator *left_iterator = nullptr;
//    BSTIterator *right_iterator = nullptr;
//
//public:
//    BSTIterator(TreeNode* root)
//        :root_node_(root) {
//        if (root_node_) {
//            left_iterator = new BSTIterator(root_node_->left );
//            right_iterator = new BSTIterator(root_node_->right);
//        }
//    }
//
//    /** @return the next smallest number */
//    int next() {
//        int result = 0;
//        if (left_iterator && left_iterator->hasNext())
//            result =  left_iterator->next();
//        else if (root_node_ != nullptr) {
//            result = root_node_->val;
//            root_node_ = nullptr;
//            left_iterator = nullptr;
//        }            
//        else if (right_iterator && right_iterator->hasNext())
//            result = right_iterator->next();
//        return result;
//    }
//
//    /** @return whether we have a next smallest number */
//    bool hasNext() {
//        return (left_iterator && left_iterator->hasNext()) 
//            || (root_node_ != nullptr)
//            || (right_iterator && right_iterator->hasNext());
//    }
//};
//
///**
// * Your BSTIterator object will be instantiated and called as such:
// * BSTIterator* obj = new BSTIterator(root);
// * int param_1 = obj->next();
// * bool param_2 = obj->hasNext();
// */
//
//
//int main() {
//
//}