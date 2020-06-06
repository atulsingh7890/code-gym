//#include <iostream>
//#include <string>
//#include <array>
//#include <unordered_map>
//#include <cassert>
//
//class Trie {
//public:
//	/** Initialize your data structure here. */
//	Trie() {		
//	}
//
//	/** Inserts a word into the trie. */
//	void insert(std::string word) {		
//		children_nodes_.insert(std::make_pair(word[0], new Trie()));
//		if (word.size() == 1) {						
//			leaf_characters_[word[0]] = true;
//		}
//		else {								
//			children_nodes_[word[0]]->insert(word.substr(1));
//		}
//	}
//
//	/** Returns if the word is in the trie. */
//	bool search(std::string word, bool ignore_death = false) {
//		bool result = false;
//		if (word.size() == 1) {	
//			auto it = leaf_characters_.find(word[0]);
//			if (!ignore_death and it == leaf_characters_.end()) {
//				result = false;				
//			}			
//			if ((ignore_death or it not_eq leaf_characters_.end()) 
//				and children_nodes_.find(word[0]) 
//				not_eq children_nodes_.end()) {
//				result = true;
//			}		
//		}
//		else {			
//			if (auto it = children_nodes_.find(word[0]) not_eq children_nodes_.end()) {
//				result =  children_nodes_[word[0]]->search(word.substr(1), ignore_death);
//			}
//		}
//		return result;
//	}
//
//	/** Returns if there is any word in the trie that starts with the given prefix. */
//	bool startsWith(std::string prefix) {
//		return search(prefix, true);
//	}
//private:	
//	std::unordered_map<char, std::unique_ptr<Trie>> children_nodes_;
//	std::unordered_map<char, bool> leaf_characters_;
//};
//
///**
// * Your Trie object will be instantiated and called as such:
// * Trie* obj = new Trie();
// * obj->insert(word);
// * bool param_2 = obj->search(word);
// * bool param_3 = obj->startsWith(prefix);
// */
//
//int main() {	
//
//	{
//		Trie obj;
//		obj.insert("apple");
//		obj.insert("p");
//		assert(true == obj.search("p"));
//		assert(false == obj.search("a"));
//		assert(true == obj.search("apple"));
//		assert(true == obj.startsWith("a"));
//		assert(true == obj.startsWith("ap"));
//		assert(true == obj.startsWith("app"));
//		assert(true == obj.startsWith("appl"));
//		assert(true == obj.startsWith("apple"));
//		assert(false == obj.startsWith("apples"));
//		obj.insert("word");
//		assert(true == obj.search("word"));
//		assert(false == obj.search("wo"));
//		assert(false == obj.search("words"));
//		obj.insert("apps");
//		obj.insert("alps");
//		assert(true == obj.search("apps"));				
//		obj.insert("app");
//		assert(true == obj.search("apps"));
//		assert(true == obj.search("app"));
//		obj.insert("apest");
//		assert(true == obj.search("apest"));
//		obj.insert("apeqrt");
//		assert(true == obj.search("apest"));
//	}
//
//	Trie trie;
//
//	trie.insert("apple");
//	assert(true == trie.search("apple"));   // returns true
//	assert(false == trie.search("app"));     // returns false
//	assert(true == trie.startsWith("app")); // returns true
//	trie.insert("app");
//	assert(true == trie.search("app"));     // returns true	
//
//}