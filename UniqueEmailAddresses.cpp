//https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3989/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::set<std::string> uniq;
        for(auto email : emails) {
            std::string new_email;
            bool local_name_processed = false;
            bool plus_encountered = false;
            for(auto ch : email) {
                if(ch == '.' && !local_name_processed) {
                    continue;
                } else if(ch == '+' && !local_name_processed) {
                    plus_encountered = true;
                    continue;
                } else if(ch == '@') {
                    local_name_processed = true;
                } else if(plus_encountered && !local_name_processed) {
                    continue;
                }
                new_email.push_back(ch);
            }
            uniq.insert(new_email);
        }
        return uniq.size();
    }
};
