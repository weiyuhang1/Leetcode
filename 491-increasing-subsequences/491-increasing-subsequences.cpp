class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        backtracking(nums, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    int cur;
    void backtracking(vector<int>& nums, int startindex) {
        if (path.size() > 1) result.push_back(path);
    //    if (path.size() == nums.size()) return;
        unordered_set<int> used;
        for (int i = startindex; i < nums.size(); i++) {
            if ((used.find(nums[i]) == used.end()) &&
                (path.empty() || nums[i] >= path.back())) {
         
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
                used.insert(nums[i]);
            }
        }
    }  
};