class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int average = quickselect(nums, nums.size() / 2, 0, nums.size() - 1);
        int dist = 0;
        for (auto num : nums) {
            dist += abs(num - average);
        }
        return dist;
    }
        

private:
    int quickselect(vector<int>& nums, int k, int l, int r) {
        if (l == r) return nums[l];
        if (l > r) return -1000;
        int x = partition(nums, l, r);
        if (k == x) {
            return nums[x];
        } else if (k < x) {
            return quickselect(nums, k, l, x - 1);
        } else {
            return quickselect(nums, k, x + 1, r);
        }
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
        
    
};