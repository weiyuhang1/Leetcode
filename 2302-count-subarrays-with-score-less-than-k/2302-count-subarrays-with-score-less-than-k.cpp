class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long sum = 0;
        long count = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
        }
        return count;
        
    }
};