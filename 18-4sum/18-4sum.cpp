class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int l, r, sum, subtarget;
        for (int i = 0; i < nums.size(); i++) {
      //      if ((nums[i] + nums [i+1])> (target - nums[i + 2] - nums[i + 3])) return result;
            if (i == 0 || nums[i] != nums[i - 1]) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (j == i + 1 || nums[j] != nums[j - 1]) {
                l = j + 1;
                r = nums.size() - 1;
                while (l < r) {
                    subtarget = target - nums[i] - nums[j];
                    sum = nums[l] + nums[r];
                    if (sum == subtarget) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                        l++;
                    } else if (sum < subtarget) {
                        l++;
                    } else {
                        r--;
                    }
                    
                }
            
            }
            }
            }
        }
        return result;
    }
};