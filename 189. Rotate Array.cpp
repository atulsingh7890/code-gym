/*
[-1,-100,3,99]
[3,100,-1,99]
[3,99,-1,100]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {      
        int starting_index = 0;        
        int elements_moved = 0;
        while(elements_moved < nums.size()) {
            int value_to_put = nums[starting_index];
            int will_move_to = (starting_index + k )% (nums.size());
            while(will_move_to != starting_index) {
                std::swap(value_to_put, nums[will_move_to]);
                elements_moved++;
                will_move_to = (will_move_to + k) % nums.size();
            }        
            std::swap(value_to_put, nums[will_move_to]);
            elements_moved++;
            starting_index++;
        }        
    }
};
