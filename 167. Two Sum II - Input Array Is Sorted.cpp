class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size() - 1;
        std::vector<int> result;
        while(s < e) {
            int sum = numbers[s] + numbers[e];
            if(sum == target) {
                result.push_back(s+1);
                result.push_back(e+1);
                break;
            }
            else if(sum < target)
                s++;
            else
                e--;
        }
        return result;
    }
};
