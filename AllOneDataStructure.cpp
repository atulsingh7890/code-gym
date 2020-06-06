//#include <unordered_map>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <cassert>
//
//class AllOne {
//private:
//
//	using KeysList = std::list<std::string>;
//	using KeyListIterator = KeysList::iterator;
//
//	struct KeyListWithSize {
//		int list_size_;
//		KeysList key_list_;
//	};
//
//	struct FrequencyListElement {
//		int frequency_count_;
//		KeyListWithSize key_list_with_size_;
//	};
//
//	using KeyAccessMapKey = std::string;
//
//	using FrequencyList = std::list<FrequencyListElement>;
//	using FrequencyListIterator = FrequencyList::iterator;
//
//	struct KeyAccessMapValue {
//		FrequencyListIterator iterator_to_frequency_list;
//		KeyListIterator  iterator_to_actual_list_node;
//	};
//		
//
//
//	using KeyAccessMap = std::unordered_map<KeyAccessMapKey, KeyAccessMapValue>;
//
//	using KeyAccessMapIterator = KeyAccessMap::iterator;
//	
//	
//	KeyAccessMap key_access_map_;
//	FrequencyList frequency_list_;
//
//
//	KeyAccessMapValue downgrade_key_frequency(KeyAccessMapIterator& key_access_map_iterator) {
//		// get the Frequency list of this key
//		FrequencyListIterator frequency_list_iterator = key_access_map_iterator->second.iterator_to_frequency_list;
//		// get the actual list where this key is residing
//		KeyListIterator key_list_iterator = key_access_map_iterator->second.iterator_to_actual_list_node;
//		// backup the actual key 
//		std::string key = *key_list_iterator;
//		// Current Frequency Count
//		int current_frequency = frequency_list_iterator->frequency_count_;
//
//		// Remove the key from the list
//		frequency_list_iterator->key_list_with_size_.key_list_.erase(key_list_iterator);
//		frequency_list_iterator->key_list_with_size_.list_size_--;
//		
//
//		KeyAccessMapValue key_access_map_value;		
//
//		if (frequency_list_iterator == frequency_list_.begin() && current_frequency == 1) {
//			// Drop this Frequency Elements Node , if underlying list size has become zero
//			if (frequency_list_iterator->key_list_with_size_.list_size_ == 0) {
//				frequency_list_.erase(frequency_list_iterator);
//			}
//			// We were already with Frequency 1, no need to do anything
//			return KeyAccessMapValue{ frequency_list_.end() , key_list_iterator };
//		}
//
//		// Store the prev Frequency List Element Node
//		FrequencyListIterator prev_frequency_node =
//			frequency_list_iterator != frequency_list_.begin()
//			? std::prev(frequency_list_iterator)
//			: frequency_list_.end();
//
//		
//		if ( prev_frequency_node != frequency_list_.end() &&
//			prev_frequency_node->frequency_count_ == current_frequency - 1) {
//			prev_frequency_node->key_list_with_size_.key_list_.push_back(key);
//			prev_frequency_node->key_list_with_size_.list_size_++;
//			key_access_map_value = { prev_frequency_node,
//					std::prev(prev_frequency_node->key_list_with_size_.key_list_.end())
//			};
//		} else {
//			// We are anyhow inserting a new max node
//			KeysList key_list;
//			key_list.push_back(key);
//			KeyListWithSize key_list_with_size{ 1, key_list };
//			FrequencyListElement frequency_list_element{ current_frequency - 1, key_list_with_size };
//			
//			FrequencyListIterator inserted_iterator =  frequency_list_.insert(frequency_list_iterator, frequency_list_element);
//			
//			key_access_map_value = {
//				inserted_iterator,
//				std::prev(inserted_iterator->key_list_with_size_.key_list_.end())
//				};
//		}
//
//		// Drop this Frequency Elements Node , if underlying list size has become zero
//		if (frequency_list_iterator->key_list_with_size_.list_size_ == 0) {
//			frequency_list_.erase(frequency_list_iterator);
//		}
//
//		return key_access_map_value;
//	}
//	
//
//
//	KeyAccessMapValue upgrade_key_frequency(KeyAccessMapIterator& key_access_map_iterator) {
//		// get the Frequency list of this key
//		FrequencyListIterator frequency_list_iterator = key_access_map_iterator->second.iterator_to_frequency_list;
//		// get the actual list where this key is residing
//		KeyListIterator key_list_iterator = key_access_map_iterator->second.iterator_to_actual_list_node;
//		// backup the actual key 
//		std::string key = *key_list_iterator;
//		// Current Frequency Count
//		int current_frequency = frequency_list_iterator->frequency_count_;
//
//		// Remove the key from the list
//		frequency_list_iterator->key_list_with_size_.key_list_.erase(key_list_iterator);
//		frequency_list_iterator->key_list_with_size_.list_size_--;
//
//		// Store the next Frequency List Element Node
//		FrequencyListIterator next_frequency_node = std::next(frequency_list_iterator);		
//
//		KeyAccessMapValue key_access_map_value;
//
//		//Now try to insert it in the next Node
//		if (next_frequency_node != frequency_list_.end() 
//			&& (next_frequency_node->frequency_count_ == current_frequency + 1)) {
//				next_frequency_node->key_list_with_size_.key_list_.push_back(key);
//				next_frequency_node->key_list_with_size_.list_size_++;
//				key_access_map_value = { next_frequency_node,
//						std::prev(next_frequency_node->key_list_with_size_.key_list_.end())
//				};
//		}
//		else {
//			// We are anyhow inserting a new max node after our current iterator
//			KeysList key_list;
//			key_list.push_back(key);
//			KeyListWithSize key_list_with_size{ 1, key_list };
//			FrequencyListElement frequency_list_element{ current_frequency + 1, key_list_with_size };
//			FrequencyListIterator inserted_iterator =  frequency_list_.insert(std::next(frequency_list_iterator), frequency_list_element);
//			key_access_map_value = {
//				inserted_iterator,
//				std::prev(inserted_iterator->key_list_with_size_.key_list_.end())
//			};
//		}
//
//		// Drop this Frequency Elements Node , if underlying list size has become zero
//		if (frequency_list_iterator->key_list_with_size_.list_size_ == 0) {
//			frequency_list_.erase(frequency_list_iterator);
//		}
//
//		return key_access_map_value;
//	}
//
//	KeyAccessMapValue push_new_key_in_frequency_list(std::string key) {
//		// Insert this key in the list of Frequency 1 keyLists
//		if (frequency_list_.begin() == frequency_list_.end()) {
//			// This is the first node we are inserting, our Frequency List is empty
//			KeysList key_list;
//			key_list.push_back(key);
//			KeyListWithSize key_list_with_size{1, key_list};
//			FrequencyListElement frequency_list_element{1, key_list_with_size };
//			frequency_list_.push_back(frequency_list_element);
//		}
//		else if(frequency_list_.begin()->frequency_count_ == 1){
//			// List with minimum at the front is already existing
//			FrequencyListElement & frequency_list_element = *frequency_list_.begin();
//			KeyListWithSize& key_list_with_size = frequency_list_element.key_list_with_size_;
//			KeysList& key_list = key_list_with_size.key_list_;
//
//			key_list.push_back(key);
//			key_list_with_size.list_size_++;
//		}
//		else {
//			KeysList key_list;
//			key_list.push_back(key);
//			KeyListWithSize key_list_with_size{ 1, key_list };
//			FrequencyListElement frequency_list_element{ 1, key_list_with_size };
//			frequency_list_.push_front(frequency_list_element);
//		}
//		
//		return { frequency_list_.begin(), std::prev(frequency_list_.begin()->key_list_with_size_.key_list_.end()) };
//	}
//
//public:
//	/** Initialize your data structure here. */
//	AllOne() {
//
//	}
//
//	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
//	void inc(std::string key) {
//		// Find the Key iterator first
//		auto it_key_access_map = key_access_map_.find(key);
//		if (it_key_access_map == key_access_map_.end()) {
//			key_access_map_[key] = push_new_key_in_frequency_list(key);
//		}
//		else {
//			// key to be updated			
//			key_access_map_[key] = upgrade_key_frequency(it_key_access_map);
//		}
//	}
//
//	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
//	void dec(std::string key) {
//		// Find the Key iterator first
//		auto it_key_access_map = key_access_map_.find(key);
//		if (it_key_access_map != key_access_map_.end()) {
//			KeyAccessMapValue key_access_map_value = downgrade_key_frequency(it_key_access_map);
//			if (key_access_map_value.iterator_to_frequency_list == frequency_list_.end()) {
//				// Frequency reached to zero
//				key_access_map_.erase(it_key_access_map);
//			}
//			else {
//				key_access_map_[key] = key_access_map_value;
//			}			
//		}
//	}
//
//	/** Returns one of the keys with maximal value. */
//	std::string getMaxKey() {
//		// return the end of our list
//		std::string result = "";
//		if (frequency_list_.begin() != frequency_list_.end()) {
//			return *(std::prev(frequency_list_.end())->key_list_with_size_.key_list_.begin());
//		}
//		return result;
//	}
//
//	/** Returns one of the keys with Minimal value. */
//	std::string getMinKey() {
//		std::string result = "";
//		if (frequency_list_.begin() != frequency_list_.end()) {
//			return *(frequency_list_.begin()->key_list_with_size_.key_list_.begin());
//		}
//		return result;
//	}
//};
//
///**
// * Your AllOne object will be instantiated and called as such:
// * AllOne* obj = new AllOne();
// * obj->inc(key);
// * obj->dec(key);
// * string param_3 = obj->getMaxKey();
// * string param_4 = obj->getMinKey();
// */
//
//int main() {
//	{
//		AllOne allone;
//		assert("" == allone.getMaxKey());
//		assert("" == allone.getMinKey());
//		allone.inc("a");
//		assert("a" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.inc("b");
//		assert("a" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.inc("c");
//		assert("a" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.inc("c");
//		assert("c" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.inc("c");
//		assert("c" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.inc("b");
//		assert("c" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.inc("c");
//		assert("c" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.dec("c");
//		assert("c" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.dec("c");
//		assert("b" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.dec("c");
//		assert("b" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//		allone.dec("c");
//		assert("b" == allone.getMaxKey());
//		assert("a" == allone.getMinKey());
//	}
//
//	{
//		AllOne all_one;
//		all_one.inc("hello");
//		all_one.inc("hello");
//		assert(all_one.getMaxKey() == "hello");
//		assert(all_one.getMinKey() == "hello");
//		all_one.inc("leet");
//		assert(all_one.getMaxKey() == "hello");
//		assert(all_one.getMinKey() == "leet");
//	}
//
//	{
//		AllOne all_one;
//		all_one.inc("a");
//		all_one.inc("b");
//		all_one.inc("b");
//		all_one.inc("c");
//		all_one.inc("c");
//		all_one.inc("c");
//		all_one.dec("b");
//		all_one.dec("b");
//		assert("a" == all_one.getMinKey());
//		all_one.dec("a");
//		assert("c" == all_one.getMaxKey());
//		assert("c" == all_one.getMinKey());
//	}
//
//
//	{
//	
//		AllOne allone;
//		allone.inc("hello");
//		allone.inc("hello");
//		allone.inc("world");
//		allone.inc("world");
//		allone.inc("hello");
//		allone.dec("world");
//		assert("hello" == allone.getMaxKey());
//		assert("world" == allone.getMinKey());
//	}
//}