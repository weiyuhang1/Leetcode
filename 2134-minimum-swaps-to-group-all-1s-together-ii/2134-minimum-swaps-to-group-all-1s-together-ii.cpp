class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        for (int num : nums) {
            ones += num;
        }
        int count = 0;
        for (int i = 0; i < ones; i++) {
            count += nums[i];
        }
        int maxcount = count;
        for (int i = 1; i < nums.size(); i++) {
            count += nums[(i + ones - 1) % nums.size()] - nums[i - 1];
            maxcount = max(maxcount, count);
        }
        return ones - maxcount;
    }
};