////https://leetcode.com/problems/time-based-key-value-store/description/
//
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <cassert>
//
//class TimeMap {
//public:
//    /** Initialize your data structure here. */
//    TimeMap() {
//
//    }
//
//    void set(std::string key, std::string value, int timestamp) {
//        underlying_map_[key].push_back({ value, timestamp });
//    }
//
//    std::string get(std::string key, int timestamp) {
//        std::string result = "";
//        auto it = underlying_map_.find(key);
//        if (it != underlying_map_.end()) {
//            std::vector<ValueTimeStamp>& values_with_timestamps = it->second;
//            int floor_time_stamp_index = FindFloorTimeStamp(values_with_timestamps, timestamp);
//            result = floor_time_stamp_index != -1 ? values_with_timestamps[floor_time_stamp_index].value_ : "";
//        }
//        return result;
//    }
//private:    
//    struct ValueTimeStamp {
//        std::string value_;
//        int timestamp_;
//    };
//
//    using ValueTimeStamps = std::vector<ValueTimeStamp>;
//
//    std::unordered_map<std::string, ValueTimeStamps> underlying_map_;
//
//
//	int FindFloorTimeStamp(const ValueTimeStamps& timestamps, const int & querry_timestamp) {
//        if (timestamps.size() <= 0 ||
//            querry_timestamp < timestamps[0].timestamp_) {
//            return -1;
//        }
//
//        if (querry_timestamp >= timestamps[timestamps.size() - 1].timestamp_) {
//            return timestamps.size() - 1;
//        }
//
//        int start = 0, end = timestamps.size() - 1;
//        while (start < end) {
//            int mid = end - ((end - start) >> 1);
//            
//            if (timestamps[mid].timestamp_ == querry_timestamp) {
//                return mid;
//            }
//            
//            if (mid < end && timestamps[mid].timestamp_ <= querry_timestamp && timestamps[mid + 1].timestamp_ > querry_timestamp) {
//                return mid;
//            }
//
//            if (mid > start && timestamps[mid - 1].timestamp_ <= querry_timestamp && timestamps[mid].timestamp_ > querry_timestamp) {
//                return mid - 1;
//            }
//
//            if (timestamps[mid].timestamp_ > querry_timestamp) {
//                end = mid - 1;
//            }
//            else {
//                start = mid + 1;
//            }
//        }
//        return -1;
//	}
//
//};
//
///**
// * Your TimeMap object will be instantiated and called as such:
// * TimeMap* obj = new TimeMap();
// * obj->set(key,value,timestamp);
// * string param_2 = obj->get(key,timestamp);
// */
//int main() {
//    TimeMap kv;
//    kv.set("foo", "bar", 1);
//    assert("bar" == kv.get("foo", 1));
//    assert("bar" == kv.get("foo", 3));
//    kv.set("foo", "bar2", 4);
//    assert("bar2" == kv.get("foo", 4));
//    assert("bar2" == kv.get("foo", 5));
//    assert("bar" == kv.get("foo", 2));
//    kv.set("foo", "bar6", 6);
//    assert("bar6" == kv.get("foo", 6));
//    assert("bar2" == kv.get("foo", 5));
//    assert("bar" == kv.get("foo", 3));
//    kv.set("foo", "bar8", 8);
//    assert("bar" == kv.get("foo", 3));
//    assert("" == kv.get("bar", 3));
//    assert("" == kv.get("foo", 0));
//    assert("bar8" == kv.get("foo", 9));
//    kv.set("foo", "bar8", 15);
//    assert("bar8" == kv.get("foo", 14));
//
//}
