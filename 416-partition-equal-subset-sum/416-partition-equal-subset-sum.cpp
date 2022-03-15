class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums){
            sum += num;
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 0;
        for (int num : nums){
            for (int j = target; j >= num; j--){
                dp[j] = max(dp[j], dp[j - num] + num);
                if (dp[j] == target) return true;
            }
        }
        return false;
    }
};