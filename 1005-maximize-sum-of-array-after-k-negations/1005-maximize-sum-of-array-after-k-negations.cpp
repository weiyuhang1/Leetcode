class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // negative to positive; positive two negates, 1 negates on the smallest one
        sort(nums.begin(), nums.end());
        int absmin = INT_MAX;
        for (int num : nums) {
            if (abs(num) < absmin)
                absmin = abs(num);
            
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (k > 0) {
                if (nums[i] < 0) {
                    sum += -nums[i];
                    k--;
                } else {
                    if (k % 2 == 0) {
                        sum += nums[i];
                    } else {
                        if (abs(nums[i]) == absmin) {
                            sum += -nums[i];
                        } else {
                            sum -= absmin * 2;
                            sum+= nums[i];
                        }
                    }
                    k = 0;
                }
            } else {
                sum += nums[i];
            }
        }
        if (k % 2 == 1) sum-= absmin * 2;
        return sum;
        
    }
};