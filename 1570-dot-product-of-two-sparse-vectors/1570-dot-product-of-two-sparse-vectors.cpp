class SparseVector {
private:
    vector<pair<int, int>> l;
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
        for (int i = 0, j = 0; i < l.size() && j < vec.l.size(); i++, j++) {
            int index1 = l[i].first;
            int index2 = vec.l[j].first;
            if (index1 == index2) {
                sum += l[i].second * vec.l[j].second;
            } else if (index1 < index2) {
                j--;
            } else {
                i--;
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);