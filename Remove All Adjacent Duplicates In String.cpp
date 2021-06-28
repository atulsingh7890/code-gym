//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3794/
class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> st;
        for(auto ch : s) {
            if(st.size() && st.top() == ch) {
                st.pop();
            } else {
                st.push(ch);
            }            
        }
        
        std::string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};
