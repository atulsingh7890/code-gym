class Solution {
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '/' || ch == '*';
    }    
public:
    int evalRPN(vector<string>& pfn) {
        std::stack<int> tokens;
        for(auto str : pfn) {
            if(str.size() == 1 && isOperator(str[0])) {
                int second = tokens.top();
                tokens.pop();
                int first = tokens.top();
                tokens.pop();
                int c = 0;                
                switch(str[0]) {
                    case '+':
                        c = first + second;                 
                        break;
                    case '-':
                        c = first - second;
                        break;
                    break;
                    case '*':
                        c = first * second;
                        break;
                    case '/':
                        c = first / second;
                        break;
                }
                tokens.push(c);                
            } else {
                tokens.push(std::atoi(str.c_str()));
            }
        }
        return tokens.top();
    }
};
