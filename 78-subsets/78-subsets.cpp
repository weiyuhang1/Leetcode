class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startindex) {
        result.push_back(path);
        if (path.size() == nums.size()) return;
        for (int i = startindex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    
};