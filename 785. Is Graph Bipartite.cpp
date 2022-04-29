class Solution {
public:
bool isBipartite(vector<vector<int>>& graph) 
    {
        const int nodes = graph.size();
        // color one by one 1 and -1 , adjacent and if same two nodes are having same color 
        // the it cant be Bipartite
        std::vector<int> color_label(nodes,0);
        for(int i = 0 ; i < nodes ; i++ )                
        {
            if(0 != color_label[i]) { 
                continue; 
            }
            
            std::queue<int> q;
            q.push(i);
            color_label[i]=1;
            while(false == q.empty())
            {
                int current_node = q.front();
                q.pop();
                for(auto neighbour : graph[current_node])
                {
                    if(0 == color_label[neighbour])
                    {
                        color_label[neighbour] = -color_label[current_node];
                        q.push(neighbour);
                    }
                    else
                    {
                        // if already colored and are of same color then we got a failure
                        if(color_label[current_node] == color_label[neighbour]) { 
                            return false;    
                        }                        
                    }
                }
            }

        }
        return true;
    }
};
