//// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3358/
//
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//
//class RandomizedSet {
//public:
//    /** Initialize your data structure here. */
//    RandomizedSet() {
//
//    }
//
//    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//    bool insert(int val) {  
//        bool result = false;
//        if (mapped_index_in_set_.find(val) == mapped_index_in_set_.end()) {            
//            underlying_container_.push_back(val);
//            mapped_index_in_set_[val] = underlying_container_.size() - 1;    
//            result = true;
//        }
//        return result;
//    }
//
//    /** Removes a value from the set. Returns true if the set contained the specified element. */
//    bool remove(int val) {
//        bool result = false;
//        auto it = mapped_index_in_set_.find(val);
//        if (it != mapped_index_in_set_.end()) {
//            std::swap(underlying_container_[it->second],
//                underlying_container_[underlying_container_.size() - 1]);
//            mapped_index_in_set_[underlying_container_[it->second]] = it->second;
//            underlying_container_.pop_back();
//            mapped_index_in_set_.erase(it);
//            result = true;
//        }
//        return result;
//    }
//
//    /** Get a random element from the set. */
//    int getRandom() {
//        return underlying_container_[rand() % underlying_container_.size()];
//    }
//private:
//    
//    std::vector<int> underlying_container_;
//    std::unordered_map<int, int> mapped_index_in_set_;
//
//};
//
///**
// * Your RandomizedSet object will be instantiated and called as such:
// * RandomizedSet* obj = new RandomizedSet();
// * bool param_1 = obj->insert(val);
// * bool param_2 = obj->remove(val);
// * int param_3 = obj->getRandom();
// */
//
//
//int main() {
//    RandomizedSet set;
//    set.insert(0);
//    set.insert(1);
//    set.remove(0);
//    set.insert(2);
//    set.remove(1);
//    set.getRandom();
//}