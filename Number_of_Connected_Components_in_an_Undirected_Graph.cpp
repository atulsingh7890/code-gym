//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3727/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // we will do a bfs
        
        
        // make a adjacency list so that we can find easily who all are neighbours to a particular node
        std::vector<std::vector<int>> adjacency_list(n, std::vector<int>());
        
        for(auto & edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        
        int result = 0;
                
        std::vector<int> visited_nodes(n, false);
        
        std::queue<int> nodes_to_process;
        
        
        for(int i = 0; i <n; ++i) {
            if(false == visited_nodes[i]) {
                nodes_to_process.push(i);            
                while(false == nodes_to_process.empty()) {
                    int current = nodes_to_process.front();
                    nodes_to_process.pop();
                    visited_nodes[current] = true;
                    for(auto n : adjacency_list[current]) {
                        if(false == visited_nodes[n]) {
                            nodes_to_process.push(n);
                        }
                    }
                }
                result++;
            }
        }
        return result;
    }
};
