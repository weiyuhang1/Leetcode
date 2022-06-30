class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int average = nums[findKthSmallest(nums, nums.size() / 2, 0, nums.size() - 1)];
        int dist = 0;
        for (auto num : nums) {
            dist += abs(num - average);
        }
        return dist;
    }
        
    int partition(vector<int>& nums, int p, int r) {
        int q = p + rand() % (r - p + 1);
        swap(nums[q], nums[r]);
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (nums[j] <= nums[r]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int findKthSmallest(vector<int>& nums, int k, int l, int r) {
        if (l == r) return l;
        if (l > r) return -1;
        int pivot = partition(nums, l, r);
        int len = pivot - l + 1;
        if (pivot == k) {
            return pivot;
        } else if (pivot > k) {
            return findKthSmallest(nums, k, l, pivot - 1);
        } else {
            return findKthSmallest(nums, k, pivot + 1, r);
        }
    }
        
    
};