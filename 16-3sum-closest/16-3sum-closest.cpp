class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = INT_MAX;
        int diff = INT_MAX;
                int sum;
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1;
            int r = nums.size() - 1;
    
            while (l < r) {
                sum = nums[l] + nums[r] + nums[i];
                if (diff > abs(target - sum)) {
                    closest_sum = sum;
                    diff = abs(target - sum);
                }
                if (sum == target){
                    return sum;
                
                } else if (sum < target) {
          
                    l++;
                } else {
                     r--;
                }
            }
            }
         
        
        
        return closest_sum;
    }

};