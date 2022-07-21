class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && diff != 0; i++) {
            int l = i + 1;
            int r = nums.size() - 1;
           
            while (l < r) {
                 int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return target - diff;
        
    }
};