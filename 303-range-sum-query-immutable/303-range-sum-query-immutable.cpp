class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp = vector<int> (nums.size() + 1, 0);
        for (int j = 1; j < dp.size(); j++) {
            dp[j] = dp[j - 1] + nums[j - 1]; 
        }
    }
    
    int sumRange(int left, int right) {
        return dp[right + 1] - dp[left];
    }
private:
    vector<int> dp;
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */