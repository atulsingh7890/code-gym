// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int nodes = patience.size();
        std::vector<std::vector<int>> adj(nodes);
        
        std::vector<int> time(nodes, -1);
        
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        std::queue<int> q;
        q.push(0);
        time[0] = 0;
        while(false == q.empty()) {
            int node = q.front(); q.pop();
            
            for(auto child : adj[node]) {
                if(time[child] == - 1) {  // not visited yet
                    time[child] = time[node] + 1;
                    q.push(child);
                }
            }
        }
        
        
        int result = 0;
        for(int i = 1; i < nodes; ++i) {
            int pending_messages_count = (2 * time[i])/patience[i] - ((2*time[i]) % patience[i] == 0 ? 1 : 0);
            int last_pending_message_time = pending_messages_count * patience[i];
            int last_message_will_reach_at = last_pending_message_time + 2 * time[i];
            result = std::max(result, last_message_will_reach_at);
        }
        return result + 1;
    }
};
