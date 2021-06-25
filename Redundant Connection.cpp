//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3791/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        /*
            lets code union find
        */
        
        const int nodes = edges.size();
        
        std::vector<int> parents(nodes, -1);
        
        auto find_parent = [&parents](int node_index)  -> int {
            while(parents[node_index] != -1) {
                node_index = parents[node_index];
            }
            return node_index;
        };
        
        
        
        
        auto union_nodes = [&parents](int current, int another)  -> void {
            parents[current] = another;
        };
        
        std::vector<int> result;
        for(auto edge : edges ) {
            
            int parent_first = find_parent(edge[0] - 1);
            int parent_second = find_parent(edge[1] - 1);
            
            if(parent_first == parent_second) {
                result = edge;
                break;
            }
            
            union_nodes(parent_first, parent_second);
        }
        
        return result;        
    }
};
