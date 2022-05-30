class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int frombegin = 1;
        int fromlast = 1;
        vector<int> result(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            result[i] *= frombegin;
            frombegin *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= fromlast;
            fromlast *= nums[i];
        }
        return result;
        
        
    }
};