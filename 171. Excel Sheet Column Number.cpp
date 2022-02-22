class Solution {
public:
    int titleToNumber(string columnTitle) {
        int number = 0;
        long multiplier = 1; //keep it long, because it getting multiplied by 26 1 extra time
        for(auto it = columnTitle.rbegin(); it != columnTitle.rend(); ++it) {
            number += (*it - 'A' + 1) * multiplier;
            multiplier *= 26;
        }
        return number;
    }
};
