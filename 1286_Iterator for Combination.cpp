//#include <string>
//#include <memory>
//#include <cassert>
//
//
//
//class CombinationIterator {
//public:
//    CombinationIterator(std::string characters, int combinationLength) 
//        : current_index_(0), string_(characters),combination_length_(combinationLength)
//    {
//        if (characters.length() > 0 && combinationLength > 1) {
//            rest_iterator_supplier_.reset(new CombinationIterator(characters.substr(1), combinationLength - 1));           
//        }      
//    }
//    
//    std::string next() {        
//        std::string result =  string_[current_index_] + (rest_iterator_supplier_ ? rest_iterator_supplier_->next() : "");
//        PerformIncrementIfRequired();
//        return result;
//    }
//
//    
//    bool hasNext() {
//        return (current_index_ < string_.size()) && (rest_iterator_supplier_ ? rest_iterator_supplier_->hasNext() : true);
//    }
//
//    void reset_iterator(const std::string & new_data) {
//        current_index_ = 0;
//        string_ = new_data;
//        rest_iterator_supplier_ ? rest_iterator_supplier_->reset_iterator(new_data.substr(1)) : (void)0;
//    }
//private:
//    int current_index_;
//    std::string string_;
//    int combination_length_;
//    std::unique_ptr<CombinationIterator> rest_iterator_supplier_;
//
//    void PerformIncrementIfRequired() {
//       if (rest_iterator_supplier_) {
//            if (false == rest_iterator_supplier_->hasNext()) {
//                current_index_++;
//                rest_iterator_supplier_->reset_iterator(string_.substr(current_index_+1));
//            }
//       }
//       else {
//
//           current_index_++;           
//       }      
//    }
//};
//
///**
// * Your CombinationIterator object will be instantiated and called as such:
// * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
// * string param_1 = obj->next();
// * bool param_2 = obj->hasNext();
// */
//
//int main() {
//    {
//		CombinationIterator iterator("abcde", 3);
//		assert(true == iterator.hasNext());
//		assert("abc" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("abd" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("abe" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("acd" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("ace" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("ade" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("bcd" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("bce" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("bde" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("cde" == iterator.next());
//		assert(false == iterator.hasNext());
//    }
//
//
//
//	{
//		CombinationIterator iterator("abcde", 2);
//		assert(true == iterator.hasNext());
//		assert("ab" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("ac" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("ad" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("ae" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("bc" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("bd" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("be" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("cd" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("ce" == iterator.next());
//		assert(true == iterator.hasNext());
//		assert("de" == iterator.next());
//		assert(false == iterator.hasNext());
//	}
//    
// }