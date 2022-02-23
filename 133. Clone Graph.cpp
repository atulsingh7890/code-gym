/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    std::map<Node*, Node*> cloned_nodes;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        auto it = cloned_nodes.find(node);
        if(it != cloned_nodes.end())
            return it->second;
        
        //cloned node does not exist, create a cloned version
        Node *cloned_node = new Node(node->val);        
        cloned_nodes[node] = cloned_node;
        for(auto & neighbour : node->neighbors) {
            cloned_node->neighbors.push_back(cloneGraph(neighbour));
        }                
        return cloned_node;
    }
};
