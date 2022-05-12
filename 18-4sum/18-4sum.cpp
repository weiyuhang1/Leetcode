class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    int sum = target - nums[i] - nums[j];
                    if (sum == nums[l] + nums[r]) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                    } else if (sum > nums[l] + nums[r]) {
                        l++;
                    } else if (sum < nums[l] + nums[r]) {
                        r--;
                    }
                    
                }
            
            }
        }
        return result;
    }
};