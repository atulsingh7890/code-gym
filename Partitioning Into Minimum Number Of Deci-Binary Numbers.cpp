class Solution {
public:
    int minPartitions(string n) {
        int result = 0;
        for(auto ch : n) {
            result = std::max(ch - '0' , result);
        }
        return result;
    }
};
