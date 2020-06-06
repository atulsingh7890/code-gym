//#include <cassert>
//#include <stack>
//
//class StockSpanner {
//
//	struct PricePoint {
//		int day_index_;
//		int price_;
//	};
//
//	std::stack<PricePoint> stack_;
//
//public:
//	StockSpanner() = default;
//
//	int next(int price) {
//		int default_answer = 1;
//		while (!stack_.empty() && stack_.top().price_ <= price) {			
//			default_answer += stack_.top().day_index_;
//			stack_.pop();
//		}
//
//		stack_.push({ default_answer, price });
//		return default_answer;
//	}
//
//};
//
//int main() {
//	StockSpanner s;
//	assert(1 == s.next(100));
//	assert(1 == s.next(80));
//	assert(1 == s.next(60));
//	assert(2 == s.next(70));
//	assert(1 == s.next(60));
//	assert(4 == s.next(75));
//	assert(6 == s.next(85));
//}