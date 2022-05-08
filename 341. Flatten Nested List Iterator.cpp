/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    void move_iterator(int index) {    
        if(index >= total_indices_)
            return;
        
        if(nested_list_[index].isInteger()) {
            value_ = new int(nested_list_[index].getInteger());
            nested_list_iterator_ = nullptr;
        } else {
             value_ = nullptr;             
            nested_list_iterator_ = new NestedIterator(nested_list_[index].getList());                        
        } 
        
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) :
    value_(nullptr)  ,
    nested_list_iterator_(nullptr),
    nested_list_(nestedList) {
        current_index_being_processed_ = 0;
        total_indices_ = nestedList.size();
        move_iterator(current_index_being_processed_);
    }
    
    int next() {
        int result = 0;        
        if(value_) {
            result = *value_;
            delete value_;
            value_ = nullptr;                            
            
        } else if(nested_list_iterator_ != nullptr){            
            result = nested_list_iterator_->next();                                               
        }
        return result;
    }
    
    bool hasNext() {
        bool has_next = false;
        if(current_index_being_processed_ < total_indices_) {
            if(value_ != nullptr || (nested_list_iterator_ && nested_list_iterator_->hasNext())) {
                has_next = true;
            } else {
                move_iterator(++current_index_being_processed_);
                has_next = hasNext();
            }
            
        }
        return has_next;
    }
    
    vector<NestedInteger> & nested_list_;
    int * value_ = nullptr;
    NestedIterator * nested_list_iterator_ = nullptr;
    int current_index_being_processed_ = 0;
    int total_indices_ = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
