class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
private:
    int count;
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';
        if (row - 1 >= 0) dfs(grid, row - 1, col);
        if (row + 1 < grid.size()) dfs(grid, row + 1, col);
        if (col - 1 >= 0) dfs(grid, row, col - 1);
        if (col + 1 < grid[0].size()) dfs (grid, row, col + 1);
    }
    
};