class Solution {
            unordered_map<int, int> mp;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        for (int num : nums) {
            if (mp.find(num) == mp.end()) {
                mp[num] = 1;
            } else {
                mp[num]++;
            }
        }
        
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        permuteRecursive(nums, temp, result);
        return result;
    }
    
private:
    void permuteRecursive(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
                                                                                      
        for (int i = 0; i < nums.size(); i++) {
            if ((i == 0 || nums[i] != nums[i - 1]) && mp[nums[i]] > 0) {
                mp[nums[i]]--;
                temp.push_back(nums[i]);
                permuteRecursive(nums, temp, result);
                temp.pop_back();
                 mp[nums[i]]++;
            }
        } 
                                                                                      
                                                                                      
    
    }
        
    
};