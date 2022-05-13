class Solution {
            vector<vector<int>> result;
        vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
        
        
    }
private:
    void backtracking(int n, int k, int startindex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
                
        }
        for (int i = startindex; i <= n - (k - path.size()) +1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};