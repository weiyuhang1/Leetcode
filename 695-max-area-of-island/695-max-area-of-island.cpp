class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int maxcount = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    maxcount = max(count, maxcount);
                }
            }
        }
        return maxcount == INT_MIN ? 0 : maxcount;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
           grid[i][j] == 0)  return;
        count++;
        grid[i][j] = 0;
        dfs(grid, i + 1, j, count);
        dfs(grid, i - 1, j, count);
        dfs(grid, i, j + 1, count);
        dfs(grid, i, j - 1, count);
        
    }
    
    
};