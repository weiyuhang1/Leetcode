class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    vector<vector<int>> pathsum(m, vector(n, 0));
        pathsum[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            pathsum[i][0] = pathsum [i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            pathsum[0][j] = pathsum[0][j - 1] + grid[0][j];
        }


        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (i == 0) {
                    pathsum[i][j] = pathsum[i][j - 1] + grid[i][j];
                    
                } else {
                    pathsum[i][j] = min(pathsum[i - 1][j], pathsum[i][j - 1]) + grid[i][j];
                }
            }
        }
        return pathsum[m - 1][n - 1];
        
        
    }

};