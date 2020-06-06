//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <list>
//#include <cassert>
//
//class FirstUnique {
//public:
//	FirstUnique(std::vector<int>& nums) {
//		for (auto n : nums) {
//			add(n);
//		}
//	}
//
//	int showFirstUnique() {
//		return ordered_unique_values_.size() > 0 ? *(ordered_unique_values_.begin()) : -1;
//
//	}
//
//	void add(int value) {
//		// Check if current value doesnt exists in our duplicates map
//		auto it_duplicates = duplicate_values_.find(value);
//		if (it_duplicates == duplicate_values_.end()) {
//			auto it = access_map_.find(value);
//			if (it == access_map_.end()) {
//				// Value doest exist , this could be potential Unique Values, at the the end of the List/queue
//				// Make sure this is not the preexisting value that we may have deleted
//				ordered_unique_values_.push_back(value);
//				// Insert this value in the access_map_ and get the iterator from the end
//				access_map_[value] = --(ordered_unique_values_.end());
//			}
//			else {
//				// Value does exist this couldn't be our unique values now, remove this from the list
//				ordered_unique_values_.erase(it->second);
//				access_map_.erase(it);
//				// This value is now seen , do not insert again if you ever see it again
//				duplicate_values_[value]++;
//			}
//		}		
//	}
//private:
//	std::unordered_map< int, std::list<int>::iterator> access_map_;
//	std::unordered_map< int, int> duplicate_values_;
//	std::list<int> ordered_unique_values_;
//};
//
///**
// * Your FirstUnique object will be instantiated and called as such:
// * FirstUnique* obj = new FirstUnique(nums);
// * int param_1 = obj->showFirstUnique();
// * obj->add(value);
// */
//
//
//int main() {
//	{
//		std::vector<int> input = { 7, 7, 7, 7, 7 };
//		FirstUnique first_unique(input);
//		assert(-1 == first_unique.showFirstUnique());
//		first_unique.add(7);
//		assert(-1 == first_unique.showFirstUnique());
//		first_unique.add(3);
//		assert(3 == first_unique.showFirstUnique());
//		first_unique.add(3);
//		assert(-1 == first_unique.showFirstUnique());
//		first_unique.add(7);
//		assert(-1 == first_unique.showFirstUnique());
//		first_unique.add(17);
//		assert(17 == first_unique.showFirstUnique());
//		first_unique.add(1);
//		assert(17 == first_unique.showFirstUnique());
//		first_unique.add(2);
//		assert(17 == first_unique.showFirstUnique());
//		first_unique.add(13);
//		assert(17 == first_unique.showFirstUnique());
//		first_unique.add(4);
//		assert(17 == first_unique.showFirstUnique());
//		first_unique.add(1);
//		assert(17 == first_unique.showFirstUnique());
//		first_unique.add(17);
//		assert(2 == first_unique.showFirstUnique());
//		first_unique.add(63);
//		assert(2 == first_unique.showFirstUnique());
//		first_unique.add(4);
//		assert(2 == first_unique.showFirstUnique());
//		first_unique.add(63);
//		assert(2 == first_unique.showFirstUnique());
//		first_unique.add(2);
//		assert(13 == first_unique.showFirstUnique());
//	}	
//}