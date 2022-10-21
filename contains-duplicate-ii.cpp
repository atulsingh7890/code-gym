//https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> ourset;
        bool result = false;
        for(int i = 0 ; i < nums.size(); ++i) {
            if ( i > k ) {
                // remove the i - k  - 1 one and then insert current one
                ourset.erase(ourset.find(nums[i-k-1]));                
            }
            
            if( ourset.find(nums[i]) != ourset.end() ) {
                result = true;
                break;
            }
            ourset.insert(nums[i]);
        }
        
        return result;
    }
};
