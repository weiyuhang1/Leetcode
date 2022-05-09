class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            s.insert(i);
        }
        
        for (int i = 0; i < nums.size() + 1; i++) {
            if (s.find(i) == s.end())
                return i;
        }
        return nums[0];
    }
};