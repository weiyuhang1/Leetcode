class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                return vector<int> {mp.find(target - nums[i])->second, i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return vector<int>{};
    /*        
            
                mp.insert({nums[i], i});

            }
        
        for (int num : nums) {
            if ((target - num == num && mp.count(num) > 1) ||
                target - num != num && mp.count(target - num) > 0) {
                vec.push_back(mp.find(num)->second);
                vec.push_back(mp.find(target - num)->second);
                return vec;
            }
        }
       return vec; */
    }
  
};