class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        sz = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > sz) pq.pop();
        return pq.top();
        
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */