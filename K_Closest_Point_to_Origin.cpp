//#include <vector>
//#include <queue>
//#include <functional>
//
//class Solution {
//    using Point = std::vector<int>;
//    using Points = std::vector<std::vector<int>>;
//
//public:
//    Points kClosest(Points & points, int K) {
//
//        auto Compare = [](const Point& point_a, const Point& point_b) {
//            return (point_a[0] + point_a[1]) > (point_b[0] + point_b[1]);
//        };
//
//        std::vector<Point> k_closest_points;
//        using MyCustomePriorityQueue =  std::priority_queue<Point, std::vector<Point>, decltype(Compare)>;
//
//
//
//		class Adapter : public MyCustomePriorityQueue {
//            using queue_elements_type = typename MyCustomePriorityQueue::container_type::value_type;
//		public:
//            Adapter(decltype(Compare) comparator, std::vector<queue_elements_type> my_container) :
//                MyCustomePriorityQueue(comparator, my_container) {}
//			typedef typename MyCustomePriorityQueue::container_type container_type;
//			container_type& get_container() { return this->c; }
//		};
//
//
//        using PriorityQueue = Adapter;
//        PriorityQueue max_heap(Compare, k_closest_points);
//
//        for (int i = 0; i < points.size(); ++i) {
//            if (i < K) {
//                max_heap.push(points[i]);
//            }
//            else {
//                max_heap.push(points[i]);
//                max_heap.pop();
//            }
//        }
//
//        return max_heap.get_container();
//    }
//};
//
//int main() {
//
//}