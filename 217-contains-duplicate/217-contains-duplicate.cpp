class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            if (set.find(num) != set.end()) {
                return true;
            } else {
                set.insert(num);
            }
        }
        return false;
    }
};