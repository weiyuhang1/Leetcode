class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        const int offset = sum;
        dp[0][offset] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum + offset; j++) {
                if (j - nums[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                if (j + nums[i - 1] <= sum + offset)
                    dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
        return dp[n][offset + target];
                              
        
        
    }
};