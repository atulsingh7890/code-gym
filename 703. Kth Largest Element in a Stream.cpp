class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto n : nums) {
            if(q.size() < k) {
                q.push(n);
            } else {
                if(q.top() < n) {
                    q.push(n);
                    q.pop();
                }
            }
        }
    }
    
    int add(int val) {
        if(q.size() < K) {
            q.push(val);
        } else {
            if(q.top() < val) {
                q.push(val);
                q.pop();
            }
        }
        return q.top();
    }
    private:
    std::priority_queue<int,std::vector<int>, std::greater<int>> q;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
