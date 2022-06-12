class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int count = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (product >= k && i <= j) {
                product /= nums[i];
                i++;
            }
            count += j - i + 1;
        }
        return count;
    }
};