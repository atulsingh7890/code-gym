class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(cost.size() == 0)
            return - 1;
        
        if(cost.size() == 1)
            return gas[0] >= cost[0] ? 0 : -1;
        
        std::vector<int> potential_starting_points;
        for(int i = 0; i < gas.size(); ++i) {
            if(gas[i] > cost[i]) {
                potential_starting_points.push_back(i);                
            }
        }
        
        int answer = -1;
        for(int i = 0; i < potential_starting_points.size(); ++i) {
            int start = potential_starting_points[i];
            int next = (start+1) % gas.size();
            int fuel = gas[start] - cost[start];
            //reached at position next;
            while(next != start) {
                //refill
                fuel = fuel + gas[next];
                //check if can go next
                if(fuel < cost[next] )
                    break;
                //actually go to next destinaion
                fuel -= cost[next];
                next = (next+1) % gas.size();     
                
            }            
            if(next == start) {
                answer = start;
                break;
            }
            
        }
        return answer;
    }
};
