////https://leetcode.com/problems/design-a-stack-with-increment-operation/
//
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//
//class CustomStack {
//private:
//    std::vector<int> underlying_container;
//    int current_top = -1;    
//public:
//    CustomStack(int maxSize) {
//        underlying_container.resize(maxSize, 0);
//        current_top = -1;
//    }
//
//    void push(int x) {
//        if (current_top < (int)underlying_container.size() - 1) {
//            underlying_container[++current_top] = x;           
//        }
//    }
//
//    int pop() {
//        std::cout << "Current Top : " << current_top << std::endl;
//        if (current_top >= 0) {
//            return underlying_container[current_top--];
//        }
//        return -1;
//    }
//
//    void increment(int k, int val) {
//        int elements_to_increment = std::min(k, (int)underlying_container.size());
//        for (int i = 0; i < elements_to_increment; ++i) {
//            underlying_container[i] += val;
//        }
//    }
//};
//
///**
// * Your CustomStack object will be instantiated and called as such:
// * CustomStack* obj = new CustomStack(maxSize);
// * obj->push(x);
// * int param_2 = obj->pop();
// * obj->increment(k,val);
// */
//
//int main() {
//    CustomStack cs(3);
//    cs.push(1);
//    cs.push(2);
//    cs.pop();
//    cs.push(2);
//    cs.push(3);
//    cs.push(4);
//    cs.increment(5, 100);
//}