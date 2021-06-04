class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // form the dead-ends to check in constant time approx
        std::unordered_map<char, std::unordered_map<char, std::unordered_map< char, std::unordered_map< char, bool>>>>  deadends_map;
        
        for(auto & deadend : deadends) {
            deadends_map[deadend[0]][deadend[1]][deadend[2]][deadend[3]] = true;
        }
        
        
        auto isDeadEnd = [&deadends_map](const std::string & str){
            // penalty only for deadends , non-deadends string will break first
            bool result = false;
            auto it = deadends_map.find(str[0]);
            if(it != deadends_map.end()) {
                auto it2 = it->second.find(str[1]);
                if( it2 != it->second.end()) {
                    auto it3 = it2->second.find(str[2]);
                    if(it3 != it2->second.end()) {
                        auto it4 = it3->second.find(str[3]);
                        if(it4 != it3->second.end()) {
                            result = true;
                        }
                    }
                }
            }
            return result;
        };
        
        // direction 0 : Clock Wise
        // direction 1 : CounterClockWise
        auto getNextCombination = [](const std::string  & str, int position, int direction) {
            std::string result = str;
            int digit = result[position] - '0';
            if(direction == 0) {
                digit = (digit + 1) % 10;           
                result[position] =  digit + '0';
            } else {                
                digit = digit == 0 ? 9 : digit - 1;               
                result[position] =  digit + '0';
            }            
            return result;
        };
        
        
        //std::vector<std::string> locks_combinations_storage;
        
        std::unordered_map<std::string, int> distance;
        std::unordered_map<std::string, bool> visited;
        
        std::queue<std::string> q;
        std::string initial_combination = "0000";
        
        // proceed only if start is not deadend
        if(false == isDeadEnd(initial_combination)) {
            q.push(initial_combination);
            distance[initial_combination] = 0;
            visited[initial_combination] = true;
        
        }        
        bool combination_found = false;
        
        while(false == q.empty()) {
            std::string curr_combination = q.front(); q.pop();            
            //std::cout << "Picking Combination " << curr_combination << " from Queue\n";
            for(int direction = 0; direction <= 1 && !combination_found ; direction++) {
                for(int pos = 0 ; pos <=3 && !combination_found; ++pos) {
                    std::string next_combination = getNextCombination(curr_combination, pos, direction);
                    auto it_in_visited = visited.find(next_combination);
                    //std::cout << "\t\tNext Combination " << next_combination << "\n";                     
                    if(false == isDeadEnd(next_combination) && it_in_visited == visited.end()) {
                        
                        visited[next_combination] = true;
                        distance[next_combination] = distance[curr_combination] + 1;
                        q.push(next_combination);
                        
                        if(next_combination == target) {
                            combination_found = true;
                            break;
                        }                        
                    }
                }
            }
            if(combination_found) {
                break;
            }
        }
        
        
        return distance.find(target) != distance.end() ? distance[target] : -1;
    }
};
