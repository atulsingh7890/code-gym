////https://leetcode.com/problems/tweet-counts-per-frequency/
//
//#include <string>
//#include <unordered_map>
//#include <set>
//#include <algorithm>
//#include <cassert>
//#include <memory>
//
//class TweetCounts {
//    using IntPair = std::pair<int, int>;
//
//    struct BinarySearchTreeNode {
//        int val_;
//        int smaller_elements_count = 0;
//        BinarySearchTreeNode* left_ = nullptr;
//        BinarySearchTreeNode* right = nullptr;
//    };
//
//    class BinarySearchTree {
//    public:
//        BinarySearchTree() : root_node_(nullptr) {}
//
//        void insert(int val) {
//            root_node_ = insert(root_node_, 0, val);
//        }
//
//        IntPair ceil_elements(int val) const {
//            std::unique_ptr<BinarySearchTreeNode> ceil_node = ceil(root_node_, val);
//            return ceil_node ?
//                IntPair{ ceil_node->val_, ceil_node->smaller_elements_count + 1 } :
//                IntPair{ -1, 0 };
//        }
//
//        IntPair floor_elements(int val) const {
//            std::unique_ptr<BinarySearchTreeNode> floor_node = floor(root_node_, val);
//            return floor_node ?
//                IntPair{ floor_node->val_, floor_node->smaller_elements_count + 1 } :
//                IntPair{ -1, 0 };
//        }
//
//    private:
//
//        std::unique_ptr<BinarySearchTreeNode> floor(std::unique_ptr<BinarySearchTreeNode> node, int val) const {
//            if (node == nullptr) {
//                return nullptr;
//            }
//            if (node->val_ == val) {
//                return node;
//            }
//            if (node->val_ > val) {
//                return floor(node->left_, val);
//            }
//
//            std::shared_ptr<BinarySearchTreeNode> floor_node = floor(node->right, val);
//            return floor_node && floor_node->val_ <= val ? floor_node : node;
//        }
//
//        std::shared_ptr<BinarySearchTreeNode> ceil(std::shared_ptr<BinarySearchTreeNode> node, int val) const {
//            if (node == nullptr) {
//                return nullptr;
//            }
//            if (node->val_ == val) {
//                return node;
//            }
//            if (node->val_ < val) {
//                return ceil(node->right, val);
//            }
//
//            std::shared_ptr<BinarySearchTreeNode> ceil_node = ceil(node->left_, val);
//            return ceil_node && ceil_node->val_ >= val ? ceil_node : node;
//        }
//
//        std::shared_ptr<BinarySearchTreeNode> insert(std::shared_ptr<BinarySearchTreeNode> node, int smaller_count, int val) {
//            if (node == nullptr) {
//                return std::make_shared<BinarySearchTreeNode>(val, smaller_count, nullptr, nullptr);
//            }
//
//            if (node->val_ > val) {
//                node->left_ = insert(node->left_, node->smaller_elements_count, val);
//                node->smaller_elements_count += 1;
//            }
//            else if (node->val_ < val) {
//                node->right = insert(node->right, node->smaller_elements_count + 1, val);
//            }
//            return node;
//        }
//
//       std::shared_ptr<BinarySearchTreeNode> root_node_;
//    };
//
//    std::unordered_map<std::string, int> range_lookup_{
//        {"minute", 60 - 1},
//        {"hour", 3600 - 1},
//        {"day", 86400 - 1},
//    };
//    std::unordered_map<std::string, BinarySearchTree> tweet_record_lookup_;
//public:
//    TweetCounts() {
//
//    }
//
//    void recordTweet(std::string tweetName, int time) {
//        tweet_record_lookup_[tweetName].insert(time);
//    }
//
//
//
//    std::vector<int> getTweetCountsPerFrequency(std::string freq, std::string tweetName, int startTime, int endTime) {
//        int range = range_lookup_[freq];
//        std::vector<int> tweet_counts;
//
//        const BinarySearchTree& retweet_times = tweet_record_lookup_[tweetName];
//
//        while (startTime < endTime) {           
//            int range_end = std::min(startTime + range, endTime);
//            IntPair ciel_element = retweet_times.ceil_elements(startTime);
//            IntPair floor_element = retweet_times.floor_elements(range_end);
//            int count = 0;            
//
//            if (ciel_element.first >= startTime
//                && ciel_element.first <= range_end
//                && floor_element.first >= startTime
//                && floor_element.first <= range_end) {
//                count = floor_element.second - ciel_element.second + 1;
//            }
//            tweet_counts.push_back(count);
//            startTime = range_end + 1;
//        }
//        return tweet_counts;
//    }
//
//
//};
//
//
///**
// * Your TweetCounts object will be instantiated and called as such:
// * TweetCounts* obj = new TweetCounts();
// * obj->recordTweet(tweetName,time);
// * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
// */
//
//int main() {
//    {
//        TweetCounts tweetCounts;
//        tweetCounts.recordTweet("tweet0", 78);
//        tweetCounts.recordTweet("tweet1", 7);
//        tweetCounts.recordTweet("tweet2", 61);
//        tweetCounts.recordTweet("tweet3", 0);
//        tweetCounts.recordTweet("tweet4", 20);
//        tweetCounts.getTweetCountsPerFrequency("minute", "tweet2", 78, 5374);
//        tweetCounts.recordTweet("tweet4", 39);
//        tweetCounts.recordTweet("tweet4", 15);
//    }
//    {
//        TweetCounts tweetCounts;
//        tweetCounts.recordTweet("tweet", 0);
//        tweetCounts.recordTweet("tweet", 60);
//        tweetCounts.recordTweet("tweet", 10);
//        tweetCounts.recordTweet("tweet", 20);
//        tweetCounts.recordTweet("tweet", 30);
//        tweetCounts.recordTweet("tweet4", 56);
//        tweetCounts.getTweetCountsPerFrequency("minute", "tweet", 1, 59);
//        tweetCounts.getTweetCountsPerFrequency("minute", "tweet", 10, 40);
//        tweetCounts.getTweetCountsPerFrequency("minute", "tweet", 0, 60);
//        tweetCounts.getTweetCountsPerFrequency("day", "tweet4", 56, 2667);
//    }
//    {
//        TweetCounts tweetCounts;
//        tweetCounts.recordTweet("tweet0", 33);
//        tweetCounts.recordTweet("tweet1", 89);
//        tweetCounts.recordTweet("tweet2", 99);
//        tweetCounts.recordTweet("tweet3", 53);
//        tweetCounts.recordTweet("tweet4", 3);
//        tweetCounts.getTweetCountsPerFrequency("hour", "tweet0", 89, 3045);
//        tweetCounts.recordTweet("tweet0", 28);
//        tweetCounts.recordTweet("tweet0", 91);
//        tweetCounts.recordTweet("tweet0", 9);
//        tweetCounts.recordTweet("tweet1", 6);
//    }
//
//}