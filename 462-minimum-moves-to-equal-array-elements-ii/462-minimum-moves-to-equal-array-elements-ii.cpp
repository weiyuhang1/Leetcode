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
        
     int partition(vector<int>& nums, int l, int r) {
        int pivot = l + rand() % (r - l + 1);
        swap(nums[pivot], nums[r]);
        int j = l - 1;
        for (int i = l; i < r; i++) {
            if (nums[i] <= nums[r]) {
                j++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[j + 1], nums[r]);
        return j + 1;
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