class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
        
    }
private:
    int partition(vector<int>& nums, int p, int r) {
        int q = rand() % (r - p + 1) + p;
        swap(nums[q], nums[r]);
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (nums[j] <= nums[r]) {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    
    void quicksort(vector<int>& nums, int p, int r) {
        if (p >= r) return;
        int q = partition(nums, p, r);
        quicksort(nums, p, q - 1);
        quicksort(nums, q + 1, r);
    }
    
};