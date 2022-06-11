class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        const int targetsum = sum - x;
        int left = 0;
        int currentsum = 0;
        int len = INT_MIN;
        int maxlen = INT_MIN;
        for (int right = 0; right < nums.size(); right++) {
            currentsum += nums[right];
            while (currentsum > targetsum && left <= right) {
                currentsum -= nums[left];
                left++;
            }
            if (currentsum == targetsum) {
                len = right - left  + 1;
                maxlen = max(len, maxlen);
            }
        }
        return maxlen == INT_MIN ? -1 : nums.size() - maxlen;
    }
};