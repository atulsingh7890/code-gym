//https://leetcode.com/problems/minimum-absolute-difference/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        std::sort(arr.begin(), arr.end());
        
        std::vector<std::vector<int>> result;
        int min_diff = std::numeric_limits<int>::max();
        for(int i = 1; i < arr.size(); ++i) {
            int current_diff = arr[i] - arr[i-1];
            
            if(current_diff == min_diff) {
                result.push_back({arr[i-1], arr[i]});
                
            }
            else if(current_diff < min_diff) {
                result.clear();
                result.push_back({arr[i-1], arr[i]});
                min_diff = current_diff;;
            }
        }
        
        return result;
    }
};
