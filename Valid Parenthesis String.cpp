//#include <iostream>
//#include <string>
//#include <stack>
//#include <cassert>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//
//class Solution {
//public :
//	bool checkValidString(std::string s) {
//		int n = s.length();
//		if (n == 0) return true;
////		bool[][] dp = new boolean[n][n];
//		std::vector<std::vector<bool>> dp(n);
//		for (int i = 0; i < n; ++i) {
//			dp[i].resize(n);
//		}
//
//		for (int i = 0; i < n; i++) {
//			if (s[i] == '*') dp[i][i] = true;
//			if (i < n - 1 &&
//				(s[i] == '(' || s[i] == '*') &&
//				(s[i+1] == ')' || s[i+1] == '*')) {
//				dp[i][i + 1] = true;
//			}
//		}
//
//		for (int size = 2; size < n; size++) {
//			for (int i = 0; i + size < n; i++) {
//				if (s[i] == '*' && dp[i + 1][i + size] == true) {
//					dp[i][i + size] = true;
//				}
//				else if (s[i] == '(' || s[i] == '*') {
//					for (int k = i + 1; k <= i + size; k++) {
//						if ((s[k] == ')' || s[k] == '*') &&
//							(k == i + 1 || dp[i + 1][k - 1]) &&
//							(k == i + size || dp[k + 1][i + size])) {
//							dp[i][i + size] = true;
//						}
//					}
//				}
//			}
//		}
//		return dp[0][n - 1];
//	}
//};
//
//////
//////class Solution {
//////public:	
//////
//////	static constexpr char open_bracket = '(';
//////	static constexpr char close_bracket = ')';
//////	static constexpr char star_character = '*';
//////
//////	struct QuerryKey {
//////		std::string input_str;
//////		//std::stack<char> parenthesis_stack;
//////		int evauluating_position;
//////
//////		bool operator==(const QuerryKey & to_compare_against) const {
//////			return (evauluating_position == to_compare_against.evauluating_position) &&
//////				(0 == input_str.compare(to_compare_against.input_str));// &&
//////				//(parenthesis_stack == to_compare_against.parenthesis_stack);
//////		}
//////
//////		bool operator<(const QuerryKey & to_compare_against) const {
//////			return (evauluating_position < to_compare_against.evauluating_position) ||
//////				(0 >= input_str.compare(to_compare_against.input_str));// &&
//////				//(parenthesis_stack.size() == to_compare_against.parenthesis_stack.size());
//////		}
//////	};
//////
//////
//////
//////	bool CheckValidString(std::string str, std::stack<char> parenthesis_stack, int current_evaluating_position, std::map<QuerryKey, bool> & lut) {
//////		if (current_evaluating_position >= str.size() && parenthesis_stack.empty()) {
//////			return true;
//////		}
//////
//////		if (current_evaluating_position >= str.size() && !parenthesis_stack.empty()) {
//////			return false;
//////		}
//////
//////		bool result = false;			
//////		if (str[current_evaluating_position] == open_bracket) {
//////			parenthesis_stack.push(open_bracket);
//////
//////			QuerryKey querry_key{ str, /*parenthesis_stack,*/ current_evaluating_position + 1 };
//////			auto it = lut.find(querry_key);
//////			if (it == lut.end()) {
//////				bool current_result = CheckValidString(str, parenthesis_stack, current_evaluating_position + 1, lut);
//////				result = current_result;
//////				lut[querry_key] = result;
//////			}
//////			else {
//////				result = it->second;
//////			}
//////			//result = CheckValidString(str, parenthesis_stack, current_evaluating_position + 1);
//////		}
//////		else if (str[current_evaluating_position] == close_bracket) {
//////			if (parenthesis_stack.size() > 0) {
//////				result = (parenthesis_stack.top() == open_bracket);
//////				parenthesis_stack.pop();
//////
//////				QuerryKey querry_key{ str,/* parenthesis_stack, */current_evaluating_position + 1 };
//////				auto it = lut.find(querry_key);
//////				if (it == lut.end()) {
//////					bool current_result = CheckValidString(str, parenthesis_stack, current_evaluating_position + 1, lut);
//////					result = current_result;
//////					lut[querry_key] = current_result;
//////				}
//////				else {
//////					result = result && it->second;
//////				}
//////
//////				//result = result && CheckValidString(str, parenthesis_stack, current_evaluating_position + 1);				
//////			}
//////			else {
//////				result = false;
//////			}
//////		}
//////		else if (str[current_evaluating_position] == star_character) {
//////			std::string with_open_bracket = str;
//////			with_open_bracket[current_evaluating_position] = '(';
//////
//////			std::string with_close_bracket = str;
//////			with_close_bracket[current_evaluating_position] = ')';
//////
//////			bool result_with_open_bracket = false;
//////			QuerryKey querry_key_open_bracket{ with_open_bracket,/* parenthesis_stack, */current_evaluating_position };
//////			auto it = lut.find(querry_key_open_bracket);
//////			if (it == lut.end()) {
//////				result_with_open_bracket = CheckValidString(with_open_bracket, parenthesis_stack, current_evaluating_position, lut);
//////				lut[querry_key_open_bracket] = result_with_open_bracket;
//////			}
//////			else {
//////				result_with_open_bracket = it->second;
//////			}
//////
//////
//////			bool result_with_close_bracket = false;
//////			QuerryKey querry_key_close_bracket{ with_close_bracket, /*parenthesis_stack,*/ current_evaluating_position };
//////			it = lut.find(querry_key_close_bracket);
//////			if (it == lut.end()) {
//////				result_with_close_bracket = CheckValidString(with_close_bracket, parenthesis_stack, current_evaluating_position, lut);
//////				lut[querry_key_close_bracket] = result_with_close_bracket;
//////			}
//////			else {
//////				result_with_close_bracket = it->second;
//////			}
//////
//////			bool result_with_empty_char = false;
//////			QuerryKey querry_key_empty_bracket{ str, /*parenthesis_stack,*/ current_evaluating_position + 1 };
//////			it = lut.find(querry_key_empty_bracket);
//////			if (it == lut.end()) {
//////				result_with_empty_char = CheckValidString(str, parenthesis_stack, current_evaluating_position + 1, lut);
//////				lut[querry_key_empty_bracket] = result_with_empty_char;
//////			}
//////			else {
//////				result_with_empty_char = it->second;
//////			}
//////
//////
//////			result = result_with_open_bracket || result_with_close_bracket || result_with_empty_char;
//////
//////			//result = CheckValidString(with_open_bracket, parenthesis_stack, current_evaluating_position)  ||
//////			//	     CheckValidString(with_close_bracket, parenthesis_stack, current_evaluating_position) ||
//////			//		 CheckValidString(str, parenthesis_stack, current_evaluating_position + 1);								
//////		}
//////		return result;
//////	}
////////
//////////	bool ValidateStack(std::stack<char> & stack_to_verify) {
//////////		bool result = true;
//////////		std::stack<char> aux_stack;
//////////		while (false == stack_to_verify.empty()) {
//////////			if (stack_to_verify.top() == close_bracket) {
//////////				aux_stack.push(stack_to_verify.top());
//////////				stack_to_verify.pop();
//////////			}
//////////			else if(stack_to_verify.top() == open_bracket) {
//////////				if (aux_stack.size() > 0 && aux_stack.top() == close_bracket) {
//////////					aux_stack.pop();
//////////					stack_to_verify.pop();
//////////				}
//////////				else {
//////////					result = false;
//////////					break;
//////////				}
//////////			}
//////////		}
//////////
//////////		return result && aux_stack.empty();
//////////	}
//////////
//////////	bool CheckValidOptimized(std::string s) {
//////////		std::stack<char> open_bracket_stack;
//////////		std::stack<char> close_bracket_stack;
//////////		std::stack<char> empty_char_stack;
//////////		for (auto ch : s) {
//////////			if (ch == open_bracket) {
//////////				
//////////				open_bracket_stack.push(open_bracket);
//////////				close_bracket_stack.push(open_bracket);
//////////				empty_char_stack.push(open_bracket);
//////////
//////////			} else if (ch == star_character) {
//////////
//////////				open_bracket_stack.push(open_bracket);
//////////				close_bracket_stack.push(close_bracket);
//////////
///////////*				if (close_bracket_stack.size() > 0 && close_bracket_stack.top() == open_bracket) {
//////////					close_bracket_stack.pop();
//////////				}			*/	
//////////
//////////			} else {
//////////
//////////				open_bracket_stack.push(close_bracket);
//////////				close_bracket_stack.push(close_bracket);
//////////				empty_char_stack.push(close_bracket);
//////////
//////////				/*if (open_bracket_stack.size() > 0 && open_bracket_stack.top() == open_bracket) {
//////////					open_bracket_stack.pop();
//////////				}
//////////
//////////				if (close_bracket_stack.size() > 0 && close_bracket_stack.top() == open_bracket) {
//////////					close_bracket_stack.pop();
//////////				}
//////////
//////////				if (empty_char_stack.size() > 0 && empty_char_stack.top() == open_bracket) {
//////////					empty_char_stack.pop();
//////////				}*/
//////////			}
//////////		}
//////////
//////////		return ValidateStack(open_bracket_stack) || ValidateStack(close_bracket_stack) || ValidateStack(empty_char_stack);
//////////	}
////
////	bool checkValidString(std::string s) {		
////		std::stack<char> string_stack;
////		std::map<QuerryKey, bool> lut;
////		return CheckValidString(s, string_stack, 0, lut);
////	}
////};
//
//
//int main() {
//
//	std::vector<std::pair<std::string, bool>> testcases = { {"(*())", true},
//	{"(", false},
//	{")", false},
//	{"()()", true},
//	{"(((((())))))", true},
//	{"(*", true},
//	{"*)", true},
//	{"*", true},
//	{"", true},
//	{"(*", true}, };
//
//
//	//std::vector<std::pair<std::string, bool>> testcases = {{"(***", true}, };
//	
//	Solution s;
//	for (auto & test : testcases) {
//		assert(test.second == s.checkValidString(test.first));
//	}
//}