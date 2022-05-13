class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return result;
        
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int n, int sum, int startindex) {
        if (sum > n) return;
        if (path.size() == k) {
            if (sum == n) result.push_back(path);
            return;
        }
        for (int i = startindex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            sum += i;
            backtracking(k, n, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
        
        
    }
    
};