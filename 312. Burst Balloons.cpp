class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        /*
        
        dp[i][j] = coins we collect bursting balloons from i to j
        dp[i][j] = is dependent on dp[i][j-1] and dp[i+1][j]  and burst the ballon at jth Position
                    we just need to find maximum varying i to j covering every sequence size
        */
        
        if(nums.size() == 1)
            return nums[0];
        
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size(), 0));
        
        //sequence is what we will consider the final burst output [ 0 to array size]
        for(int sequence_size = 0; sequence_size < nums.size(); ++sequence_size) {
            
            // iterate over each Continous Sequence [ 0.....size() - sequenc_size ]
            for(int sequence_start = 0; sequence_start < nums.size() - sequence_size; ++sequence_start) {
                
                int sequence_end = sequence_start + sequence_size;
                // lets consider the last ballon to burst to vary from sequence start to sequence end
				for (int last_baloon_left_to_burst = sequence_start; last_baloon_left_to_burst <= sequence_end; last_baloon_left_to_burst++) {
                
                int previous_baloon_value = sequence_start > 0 ? nums[sequence_start - 1] : 1;
				int next_baloon_value = sequence_end < nums.size() - 1 ? nums[sequence_end + 1] : 1;
                
                int last_baloon_to_burst_answer = previous_baloon_value * nums[last_baloon_left_to_burst] * next_baloon_value;
					int answer_collated_from_left_part = last_baloon_left_to_burst > sequence_start ? dp[sequence_start][last_baloon_left_to_burst - 1] : 0;
					int answer_collated_from_right_part = last_baloon_left_to_burst < sequence_end ? dp[last_baloon_left_to_burst +1][sequence_end] : 0;

					dp[sequence_start][sequence_end] = std::max(
						dp[sequence_start][sequence_end],
						answer_collated_from_left_part + last_baloon_to_burst_answer + answer_collated_from_right_part
					);
                }
                
            }
            
        }
        
        return dp[0][nums.size() - 1];
        
        
    }
};
