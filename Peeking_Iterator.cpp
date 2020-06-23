////https://leetcode.com/problems/peeking-iterator/
//
//
//#include <vector>
//using namespace std;
//
///*
// * Below is the interface for Iterator, which is already defined for you.
// * **DO NOT** modify the interface for Iterator.
// *
// *  class Iterator {
// *		struct Data;
// * 		Data* data;
// *		Iterator(const vector<int>& nums);
// * 		Iterator(const Iterator& iter);
// *
// * 		// Returns the next element in the iteration.
// *		int next();
// *
// *		// Returns true if the iteration has more elements.
// *		bool hasNext() const;
// *	};
// */
//
//class Iterator {
//private:
//    std::vector<int>::const_iterator current_;
//    std::vector<int>::const_iterator end_;
//public:
//    Iterator(const std::vector<int>& nums) {
//        current_ = nums.begin();
//        end_ = nums.end();
//    }
//
//    int next() {
//        return *(current_++);
//    }
//
//    bool hasNext() const {
//        return current_ != end_;
//    }
//};
//
//class PeekingIterator : public Iterator {
//private:
//    int next_value_ = -1;
//    bool next_cached_ = false;
//public:
//
//    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
//        // Initialize any member here.
//        // **DO NOT** save a copy of nums and manipulate it directly.
//        // You should only use the Iterator interface methods.
//
//    }
//
//    // Returns the next element in the iteration without advancing the iterator.
//    int peek() {
//        next_value_ = Iterator::next();
//        next_cached_ = true;
//        return next_value_;
//        //return Iterator::next();
//    }
//
//    // hasNext() and next() should behave the same as in the Iterator interface.
//    // Override them if needed.
//    int next() {
//        if (!next_cached_) {
//            next_value_ = Iterator::next();
//        }
//        next_cached_ = false;
//        return next_value_;
//        // return Iterator::next();
//    }
//
//    bool hasNext() const {
//        return Iterator::hasNext();
//    }
//};
//
//int main() {
//    std::vector<int> input{1,2,3,4};
//    PeekingIterator pk(input);
//    pk.hasNext();
//    pk.peek();
//    pk.next();
//}