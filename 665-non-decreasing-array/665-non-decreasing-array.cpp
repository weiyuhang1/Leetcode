class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (i - 1 >= 0 && nums[i - 1] > nums[i + 1]) nums[i + 1] = nums[i];
                if (count > 1) return false;
            }
        }
        return true;
    }
};