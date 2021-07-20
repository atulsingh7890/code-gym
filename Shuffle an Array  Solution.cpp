class Solution {
public:
    Solution(vector<int>& nums) {
        internal_container_ = nums;
        original_container_ = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        internal_container_ = original_container_;
        return original_container_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < internal_container_.size(); ++i) {
            
            int index_to_swap = std::rand() % (internal_container_.size() - i) + i;
            std::swap(internal_container_[i], internal_container_[index_to_swap]);            
        }
        return internal_container_;
    }
private:
    std::vector<int> internal_container_;
    std::vector<int> original_container_;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
