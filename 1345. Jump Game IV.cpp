class Solution {
public:
    int minJumps(vector<int>& arr) {
     /*its sort of graph where there is an edge between node[i] -> node[i+1] and node[i-1] and all the edges with same value
        now we have node[0] = 0
        we need to find distance from node[0] to node[N-1], lets use BFS , something i can recall like Djikstra
                 
     */
        
        std::unordered_map<int, std::vector<int>> present_at_map;
        for(int i = 0; i < arr.size(); ++i) {
            present_at_map[arr[i]].push_back(i);
        }
        
        const int infinity = std::numeric_limits<int>::max();
        std::vector<int> distance(arr.size(), infinity);
        
        std::vector<int> visited(arr.size(), 0);
        
        
        std::queue<int> q;
        q.push(0);
        visited[0] = 1;
        distance[0] = 0;
        
        while(!q.empty()) {
            int current_index = q.front();
            q.pop();
                        
            
            //update distance of all its neightbours and push to queue to update for their neighbours
            if(current_index < arr.size() - 1 && 0 == visited[current_index+1]) {
                q.push(current_index+1);
                visited[current_index+1] = 1;
                distance[current_index+1] = distance[current_index] + 1;
            }
            if(current_index > 0  && 0 == visited[current_index-1]) {
                q.push(current_index-1);
                visited[current_index-1] = 1;
                distance[current_index-1] = distance[current_index] + 1;
            }
            
            auto it = present_at_map.find(arr[current_index]);
            if(it != present_at_map.end()) {
                //now push all the node this value is present
                for(auto neighbour_with_same_value : it->second) {
                    if(0 == visited[neighbour_with_same_value]) {
                        q.push(neighbour_with_same_value);
                        visited[neighbour_with_same_value] = 1;
                        distance[neighbour_with_same_value] = distance[current_index] + 1;
                    }
                }
                
                //now map is processed delete it so that its not checked in the next occurrence of the same number
                present_at_map.erase(it);
                
            }                        
        }        
        return distance[arr.size()-1];        
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /*
        Jumping back n forth is the tricky thing in this problem here
        so we have to take that into also account
        dp[i][0] : min steps to reach i from left side
        dp[i][1] : min steps to reach i from right side
        result[i] = min(dp[i][0], dp[i][1]) : Steps to reach at position i
        
        for i =0 
        dp[0][0] = 0
        dp[0][1] = -1 , we need to calculate 
                 = std::min({ result[1] + 1, 
        
                std::vector<int> result(arr.size(), std::numeric_limits<int>::max());
        std::unordered_map<int, std::vector<int>> present_at_map;
        for(int i = 0; i < arr.size(); ++i) {
            present_at_map[arr[i]].push_back(i);
        }
        
        result[0] = 0;
        for(int i = 0; i < arr.size(); ++i) {
            int steps_to_reach_current_index = result[i];
            //now iterate over all positions where result[0] is present
            int min_steps_from_indices_with_same_value = std::numeric_limits<int>::max();
            for(auto index : present_at_map[arr[i]]) {
                if(index != i) {
                    min_steps_from_indices_with_same_value = std::min(min_steps_from_indices_with_same_value, result[index]);
                }
            }
            
            if(i > 0 && result[i-1] < std::numeric_limits<int>::max()) {
                steps_to_reach_current_index = std::min(steps_to_reach_current_index, result[i-1] + 1);
            }
            
            if(i < arr.size()-1 && result[i+1] < std::numeric_limits<int>::max()) {
                steps_to_reach_current_index = std::min(steps_to_reach_current_index, result[i+1] + 1);
            }
            
            if(min_steps_from_indices_with_same_value < std::numeric_limits<int>::max())
                steps_to_reach_current_index = std::min(steps_to_reach_current_index, min_steps_from_indices_with_same_value + 1);
            
            result[i] = steps_to_reach_current_index;
            //std::cout << " i : " << arr[i] << ", " << i << " " << result[i] << "\n";
            
        }
        //std::cout << '----' << "\n";
        for(int i = 0; i < arr.size(); ++i) {
            int steps_to_reach_current_index = result[i];
            //now iterate over all positions where result[0] is present
            int min_steps_from_indices_with_same_value = std::numeric_limits<int>::max();
            for(auto index : present_at_map[arr[i]]) {
                if(index != i) {
                    min_steps_from_indices_with_same_value = std::min(min_steps_from_indices_with_same_value, result[index]);
                }
            }
            
            if(i > 0 && result[i-1] < std::numeric_limits<int>::max()) {
                steps_to_reach_current_index = std::min(steps_to_reach_current_index, result[i-1] + 1);
            }
            
            if(i < arr.size()-1 && result[i+1] < std::numeric_limits<int>::max()) {
                steps_to_reach_current_index = std::min(steps_to_reach_current_index, result[i+1] + 1);
            }
            
            if(min_steps_from_indices_with_same_value < std::numeric_limits<int>::max())
                steps_to_reach_current_index = std::min(steps_to_reach_current_index, min_steps_from_indices_with_same_value + 1);
            
            result[i] = steps_to_reach_current_index;
            //std::cout << " i : " << arr[i] << ", " << i << " " << result[i] << "\n";
            
        }
        
        return result[arr.size()-1];*/
   
        
        
      
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
        
        
       
};
