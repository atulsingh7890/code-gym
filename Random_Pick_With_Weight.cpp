//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdlib>
//#include <ctime>
//
//class Solution {
//    struct Range {
//        long start_;
//        long end_;
//        int index_;
//    };
//public:
//    Solution(const std::vector<int>& w) {      
//        range_timeline_length = 0;
//        for (int i = 0; i < w.size(); ++i) {
//            if (w[i] != 0) {
//				range_vector_.push_back({ range_timeline_length, range_timeline_length + w[i] - 1, i });
//				range_timeline_length += w[i];
//            }            
//        }
//
//        auto RangeComparator = [](const Range& a, const Range& b) {
//            return a.start_ < b.start_;
//        };
//
//        std::sort(range_vector_.begin(), range_vector_.end(), RangeComparator);
//
//        std::srand(std::time(nullptr));
//    }
//
//    int pickIndex() {		
//		return PerformBinarySearch(std::rand() % range_timeline_length);
//    }
//private:
//
//	int PerformBinarySearch(const long & value) {
//		int left = 0;
//		int right = range_vector_.size() - 1;
//		while (left <= right) {
//			int mid = (left + right) / 2;
//			if (value >= range_vector_[mid].start_ && value <= range_vector_[mid].end_) {
//				return range_vector_[mid].index_;
//			}
//			if (value < range_vector_[mid].start_) {
//				right = mid - 1;
//			}
//			else {
//				left = mid + 1;
//			}
//		}
//		return -1;
//	}
//
//
//    std::vector<Range> range_vector_;
//    long range_timeline_length = 0;
//};
//
///**
// * Your Solution object will be instantiated and called as such:
// * Solution* obj = new Solution(w);
// * int param_1 = obj->pickIndex();
// */
//
//int main(){
// 
//    Solution s({ 1,0,3,4 });
//    for (int i = 0; i < 10; ++i) {
//        std::cout << "Randomly Choosen :  " << s.pickIndex() << std::endl;
//    }
//
//}