//#include <iostream>
//#include <stack>
//#include <algorithm>B
//
//
//class MinStack {
//public:
//	/** initialize your data structure here. */
//	std::stack<int> min_stack_;
//	std::stack<int> underlying_stack_;
//	MinStack() {
//
//	}
//
//	void push(int x) {
//		underlying_stack_.push(x);
//		int min = min_stack_.size() > 0 ? std::min(min_stack_.top(), x) : x;
//		min_stack_.push(min);
//	}
//
//	void pop() {
//		underlying_stack_.pop();
//		min_stack_.pop();
//
//	}
//
//	int top() {
//		return underlying_stack_.top();
//	}
//
//	int getMin() {
//		return min_stack_.top();
//	}
//};
//
///**
// * Your MinStack object will be instantiated and called as such:
// * MinStack* obj = new MinStack();
// * obj->push(x);
// * obj->pop();
// * int param_3 = obj->top();
// * int param_4 = obj->getMin();
// */
//
//
//int main() {
//
//	MinStack *obj = new MinStack();
//	obj->push(-2);
//	obj->push(0);
//	obj->push(-3);
//	std::cout << obj->getMin() << std::endl;
//	obj->pop();
//	std::cout << obj->top() << std::endl; 
//	std::cout << obj->getMin() << std::endl;
//
//}