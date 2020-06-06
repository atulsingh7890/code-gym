//#include <iostream>
//#include <list>
//#include <utility>
//#include <map>
//#include <cassert>
//
//
///**
// * Your LRUCache object will be instantiated and called as such:
// * LRUCache* obj = new LRUCache(capacity);
// * int param_1 = obj->get(key);
// * obj->put(key,value);
// */
//
//class LRUCache {
//public:
//	using KVPair = std::pair<int, int>;
//	using DoublyLinkedList = std::list<KVPair>;
//	using AccessMap = std::map< int, DoublyLinkedList::iterator >;
//
//	LRUCache(int capacity)
//		: max_capacity_(capacity)
//	{}
//
//	int get(int key) {
//		AccessMap::const_iterator it = access_map_.find(key);
//		if (it == access_map_.end()) {
//			return -1;
//		}
//
//		DoublyLinkedList::iterator it_list = access_map_[key];
//		// Get the Node from List and push it in Front of DLL
//		doubly_linked_list_.splice(doubly_linked_list_.begin(), doubly_linked_list_, it_list);
//		return it_list->second;
//	}
//
//	void put(int key, int value) {
//
//		// Check if key is already there, just modify the value and push it to front.
//		{
//			AccessMap::const_iterator it = access_map_.find(key);
//			if (it != access_map_.end()) {
//				it->second->second = value;
//				DoublyLinkedList::iterator it_list = access_map_[key];
//				// Get the Node from List and push it in Front of DLL
//				doubly_linked_list_.splice(doubly_linked_list_.begin(), doubly_linked_list_, it_list);
//				return;
//			}
//		}
//
//		if (access_map_.size() == max_capacity_) {
//			// max_capacity is reached first remove the least recently used element from our DLL
//			int key = doubly_linked_list_.rbegin()->first;
//
//			doubly_linked_list_.pop_back();
//			// Erase this key entry from access map
//			access_map_.erase(access_map_.find(key));
//		}
//
//
//		// Now we have a slot to insert the element, Insert at the Front
//		KVPair kv_pair = std::make_pair(key, value);
//		doubly_linked_list_.push_front(kv_pair);
//		access_map_[key] = doubly_linked_list_.begin();
//	}
//private:
//	int max_capacity_;
//	DoublyLinkedList doubly_linked_list_;
//	AccessMap  access_map_;
//};
//
//int main()
//{
//	{
//		LRUCache cache(2 /* capacity */);
//		cache.put(1, 1);
//		cache.put(2, 2);
//		assert(1 == cache.get(1));       // returns 1
//		cache.put(3, 3);    // evicts key 2
//		assert(-1 == cache.get(2));       // returns -1 (not found)
//		cache.put(4, 4);    // evicts key 1
//		assert(-1 == cache.get(1));       // returns -1 (not found)
//		assert(3 == cache.get(3));       // returns 3
//		assert(4 == cache.get(4));       // returns 4
//	}	
//
//	{
//		LRUCache cache(1 /* capacity */);
//		assert(-1 == cache.get(1));   // returns -1
//		cache.put(1, 1);   
//		cache.put(2, 2);   // evicts 1
//		assert(-1 == cache.get(1));       // returns -1
//		assert(2 == cache.get(2));       // returns 2
//		cache.put(2, 4);	// Update the value of Key 2
//		assert(2 != cache.get(2));       // returns 2
//		assert(4 == cache.get(2));       // returns 2
//
//
//		cache.put(3, 3);    // evicts key 2
//		assert(-1 == cache.get(2));       // returns -1 (not found)
//		cache.put(4, 4);    // evicts key 3
//		assert(-1 == cache.get(1));       // returns -1 (not found)
//		assert(-1 == cache.get(3));       // returns 3
//		assert(4 == cache.get(4));       // returns 4
//	}
//
//	{
//		LRUCache cache(2 /* capacity */);
//		cache.put(2, 1);
//		cache.put(1, 1);
//		cache.put(2, 3);
//		cache.put(4, 1);
//		assert(-1 == cache.get(1));   // returns -1		
//		assert(3 == cache.get(2));       // returns 3
//	}
//}