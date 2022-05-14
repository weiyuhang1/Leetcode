class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startindex) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size() && candidates[i] + sum <= target; i++) {
            if (i == startindex || candidates[i] != candidates[i - 1]) {
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates, target, sum, i + 1);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }
    
    
};