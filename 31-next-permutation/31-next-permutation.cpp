class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0) return;
        int i = nums.size() - 2;
         while (nums[i] >= nums[i + 1]) {
            if (i == 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
            i--;
        } 
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        
    }
};