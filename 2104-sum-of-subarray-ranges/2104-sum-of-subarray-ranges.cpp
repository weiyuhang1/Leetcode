class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long int sum = 0;
        const int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int maximum = nums[i];
            int minimum = nums[i];
            for (int j = i + 1; j < n; j++) {
                maximum = max(maximum, nums[j]);
                minimum = min(minimum, nums[j]);
                sum += maximum - minimum;
            }
        }
        return sum;
    }
};