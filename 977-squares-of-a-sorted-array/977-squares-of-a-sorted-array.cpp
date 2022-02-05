class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> result(n);
        for (int k = n-1; k >= 0; k--){
            if (nums[i] * nums[i] >= nums[j] * nums[j]){
                result[k] = pow(nums[i],2);
                i++;
            }else{
                result[k] = pow(nums[j],2);
                j--;
            }
        }
        return result;
        
        
    }
};