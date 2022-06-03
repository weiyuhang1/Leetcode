class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp = vector<int> (nums.size(), 0);
        dp[0] = nums[0];
        for (int j = 1; j < dp.size(); j++) {
            dp[j] = dp[j - 1] + nums[j]; 
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return dp[right];
        return dp[right] - dp[left - 1];
    }
private:
    vector<int> dp;
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */