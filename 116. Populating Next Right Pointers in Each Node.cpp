//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        
        std::queue<Node*> qs[2];
        int currentQ = 0;
        
        qs[currentQ].push(root);
        
        while(false == qs[currentQ].empty() || false == qs[1-currentQ].empty()) {
            
            while(false == qs[currentQ].empty()) {
                Node * currentNode = qs[currentQ].front();
                qs[currentQ].pop();
                
                currentNode->next = qs[currentQ].empty() ?  nullptr : qs[currentQ].front();
                
                if(currentNode->left) {
                    qs[1-currentQ].push(currentNode->left);
                }
                if(currentNode->right) {
                    qs[1-currentQ].push(currentNode->right);
                }                
            }
            currentQ = 1 - currentQ;
        }
        
        return root;
    }
};
