class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return nums[findKthSmallest(nums, nums.size() - k, 0, nums.size() - 1)];
    }
    
    int findKthSmallest(vector<int>& nums, int k, int l, int r) {
        if (l == r) return l;
        int pivot = partition(nums, l, r);
        if (pivot == k) {
            return pivot;
        } else if (pivot > k) {
            return findKthSmallest(nums, k, l, pivot - 1);
        } else {
            return findKthSmallest(nums, k, pivot + 1, r);
        }
    }
    
    int partition(vector<int>& nums, int p, int r) {
        int q = p + rand() % (r - p + 1);
        swap(nums[q], nums[r]);
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (nums[j] < nums[r]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        i++;
        swap(nums[i], nums[r]);
        return i;
    }
    
    
    
};