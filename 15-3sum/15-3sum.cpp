class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
    //    if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        int target = 0;
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i] != nums[i - 1])
                twoSum(nums, i, result);
        }
         
        
        
        return result;
    }
private:
      void twoSum(vector<int> numbers, int i, vector<vector<int>>& result) {
        int l = i + 1;
        int r = numbers.size() - 1;
        int sum;
        while (l < r) {
            sum = numbers[l] + numbers[r] + numbers[i];
            if (sum == 0){
                result.push_back({numbers[i], numbers[l], numbers[r]});
                l++;
                r--;
                while (l < r && numbers[l] == numbers[l - 1]) {
                    l++;
                }
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
      }
    
};
