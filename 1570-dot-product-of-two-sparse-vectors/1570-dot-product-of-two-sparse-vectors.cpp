class SparseVector {
private:
    list<pair<int, int>> l;
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                l.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        while (!l.empty() && !vec.l.empty()) {
            int index1 = l.front().first;
            int index2 = vec.l.front().first;
            if (index1 == index2) {
                sum += l.front().second * vec.l.front().second;
                l.pop_front();
                vec.l.pop_front();
            } else if (index1 < index2) {
                l.pop_front();
            } else {
                vec.l.pop_front();
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);