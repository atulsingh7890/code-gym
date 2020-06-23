////https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
//
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//
//class RandomizedCollection {
//public:
//    /** Initialize your data structure here. */
//    RandomizedCollection() {
//
//    }
//
//    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
//    bool insert(int val) {
//        bool result = false;
//        if (mapped_index_in_set_.find(val) == mapped_index_in_set_.end()) {            
//            result = true;
//        }
//        underlying_container_.push_back(val);
//        mapped_index_in_set_[val].push_back(underlying_container_.size() - 1);
//        return result;
//    }
//
//    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
//    bool remove(int val) {
//        bool result = false;
//        auto it = mapped_index_in_set_.find(val);
//        if (it != mapped_index_in_set_.end()) {
//            std::vector<int>& indices = it->second;
//            int last_element = underlying_container_[underlying_container_.size() - 1];
//            std::vector<int>& last_element_indices = mapped_index_in_set_[last_element];
//
//            std::swap(underlying_container_[indices[indices.size()-1]],
//                underlying_container_[underlying_container_.size() - 1]);
//
//            // Now swap the last indices also        
//            std::swap(indices[indices.size() - 1], last_element_indices[last_element_indices.size() - 1]);
//            std::sort(last_element_indices.begin(), last_element_indices.end());
//                        
//            underlying_container_.pop_back();
//            indices.pop_back();
//            if (indices.size() == 0)
//                mapped_index_in_set_.erase(it);
//            result = true;
//        }
//        return result;
//    }
//
//    /** Get a random element from the collection. */
//    int getRandom() {
//        return underlying_container_[rand() % underlying_container_.size()];
//    }
//
//private:
//
//    std::vector<int> underlying_container_;
//    std::unordered_map<int, std::vector<int>> mapped_index_in_set_;
//};
//
///**
// * Your RandomizedCollection object will be instantiated and called as such:
// * RandomizedCollection* obj = new RandomizedCollection();
// * bool param_1 = obj->insert(val);
// * bool param_2 = obj->remove(val);
// * int param_3 = obj->getRandom();
// */
//
//int main() {
//    RandomizedCollection rc;
//    //rc.insert(1);
//    //rc.insert(1);
//    //rc.insert(2);
//    //rc.getRandom();
//    //rc.remove(1);
//    //rc.getRandom();
//    //rc.remove(1);
//    rc.insert(10);
//    rc.insert(10);
//    rc.insert(20);
//    rc.insert(20);
//    rc.insert(30);
//    rc.insert(30);
//    rc.remove(10);
//    rc.remove(20);
//    rc.remove(20);
//    rc.remove(10);
//    rc.remove(30);
//    rc.insert(40);
//    rc.remove(30);
//    rc.remove(30);
//    rc.getRandom();
//
//}