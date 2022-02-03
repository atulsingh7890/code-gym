class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //let store all pairs sum of nums1 and nums2 in a map
        std::unordered_map<int,int> pair_first_map;
        for(auto n1 : nums1) {
            for(auto n2 : nums2) {
                pair_first_map[n1+n2]++;
            }
        }
        
        int result = 0;
        //now lets get the other pairs from n3 and n4
        for(auto n3 : nums3) {
            for(auto n4: nums4) {
                auto it = pair_first_map.find(-(n3+n4));
                if(it != pair_first_map.end()) {
                    result += it->second;
                }
            }
        }
        return result;
    }
};
