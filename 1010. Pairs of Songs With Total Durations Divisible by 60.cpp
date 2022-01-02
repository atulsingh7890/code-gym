class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        std::unordered_map<int,int> existing;
        for(auto t : time) {
            int transformed = t % 60;
            if(transformed != 0) {
                auto it = existing.find(60 - transformed);
                if(it != existing.end()) {
                    result += it->second;
                }
            } else {
                auto it = existing.find(0);
                if(it != existing.end()) {
                    result += it->second;
                }
            }
            existing[transformed]++;
        }
        return result;
    }
};
