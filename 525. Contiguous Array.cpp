class Solution {
public:
	int findMaxLength(std::vector<int>& nums) {
		int max_length = 0;		
		std::map<int,int> sum_seen_so_far;
		sum_seen_so_far[0] = -1;

		int sum = 0;

		for (int i = 0; i < nums.size(); ++i) {
			nums[i] ? sum-- : sum++;

			if (sum_seen_so_far.find(sum) != sum_seen_so_far.end()) {				
				max_length = std::max(max_length, i - sum_seen_so_far[sum]);
			}
			else {
				sum_seen_so_far[sum] = i;
			}
		}
		return max_length;
	}
};
