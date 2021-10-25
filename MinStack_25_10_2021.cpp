//https://leetcode.com/problems/min-stack/
class MinStack {
private:
    std::stack<std::pair<int,int>> _minstack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int new_min = val;
        if(false == _minstack.empty()) {
            new_min = std::min(new_min, _minstack.top().second);
        }
        _minstack.push({val, new_min});
    }
    
    void pop() {
        _minstack.pop();
    }
    
    int top() {
        return _minstack.top().first;
    }
    
    int getMin() {
        return _minstack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
