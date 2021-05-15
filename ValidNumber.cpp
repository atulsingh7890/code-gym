//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
class Solution {
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
    bool isExponent(char ch) {
        return ch == 'e' || ch == 'E';
    }
    
    bool isSign(char ch) {
        return ch == '-' || ch == '+';
    }
    
    bool isValidNumber(std::string s) {
        bool sign_encountered = false;
        bool dot_encountered = false;
        bool digit_encountered = false;
        
        bool result = true;
        
        for(auto ch : s) {
            if(isSign(ch) && false == sign_encountered && false == dot_encountered && false == digit_encountered) {
                sign_encountered = true;
            } else if(ch == '.' && false == dot_encountered) {
                dot_encountered = true;
            } 
            else if(isDigit(ch)) {
                digit_encountered = true;
            } else {
                result = false;
                break;
            }
        }
        
        //std::cout <<"rresult foor : " << s << " :  " << result << "\n";    
        return result && digit_encountered;
    }
    
public:
    bool isNumber(string s) {
        
        bool result = true;
        
        int exponent_index = 0;
        bool exponent_present = false;
        bool dot_after_exponent = false;
        
        for(int i = 0; i < s.size(); ++i) {
            if(isExponent(s[i]) && false == exponent_present) {
                exponent_index = i;
                exponent_present = true;
            } else if(isExponent(s[i]) && true == exponent_present) {
                result = false;
                break;
            } else if(exponent_present && s[i] == '.') {
                result = false;
                break;
            }
        }
        
        if(false == result || (s.size() > 1 && exponent_index == s.size() - 1))
            return false;
        
        //std::cout << "-->" << exponent_index <<"\n";
        
        if(exponent_index == 0) {
            return isValidNumber(s);
        } else {
            return isValidNumber(s.substr(0,exponent_index)) && isValidNumber(s.substr(exponent_index+1, s.size() - exponent_index));
        }
    }
};
