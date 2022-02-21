class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element = 0;
        int majoriy_element_count = 0;
        for(auto e : nums) {
            if( e == majority_element) {                
                majoriy_element_count++;
            } else if(majoriy_element_count > 0){
                majoriy_element_count--;
            }
            
            if(majoriy_element_count == 0) {
                majoriy_element_count = 1;
                majority_element = e;
            }
        }
        return majority_element;
    }
};
