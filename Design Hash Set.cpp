////https://leetcode.com/problems/design-hashset/
//
//#include <array>
//#include <cassert>
//
//class MyHashSet {
//public:
//    /** Initialize your data structure here. */
//    MyHashSet()
//    {
//        std::fill(bit_set_.begin(), bit_set_.end(), 0);
//    }
//
//    void add(int key) {
//        bit_set_[key >> 3] = bit_set_[key >> 3] | (1 << (7 - (key % 8)));
//    }
//
//    void remove(int key) {
//        if (true == contains(key)) {
//            bit_set_[key >> 3] = bit_set_[key >> 3] ^ (1 << (7 - (key % 8)));
//        }	
//    }
//
//    /** Returns true if this set contains the specified element */
//    bool contains(int key) {
//        return (bit_set_[key >> 3] & (1 << (7 - (key % 8)))) > 0;
//    }
//private:
//    static constexpr int max_capacity = 1000000 >> 3;
//    std::array<unsigned char, max_capacity> bit_set_;
//};
//
///**
// * Your MyHashSet object will be instantiated and called as such:
// * MyHashSet* obj = new MyHashSet();
// * obj->add(key);
// * obj->remove(key);
// * bool param_3 = obj->contains(key);
// */
//
//int main() {
//    MyHashSet hash_set;
//    hash_set.add(1);
//    hash_set.add(2);
//    assert(true == hash_set.contains(1));
//    assert(false == hash_set.contains(3));
//    hash_set.add(2);
//    assert(true == hash_set.contains(2));
//    hash_set.remove(2);
//    assert(false == hash_set.contains(2));
//}