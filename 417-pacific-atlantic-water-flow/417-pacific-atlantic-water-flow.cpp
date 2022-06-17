class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, atlantic);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, m - 1, j, atlantic);
                
        }
        
        
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
private:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        if (visited[i][j] == true) return;
        const int m = heights.size();
        const int n = heights[0].size();
        visited[i][j] = true;
        if (i + 1 < m && heights[i + 1][j] >= heights[i][j]) dfs(heights, i + 1, j, visited);
        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) dfs(heights, i - 1, j, visited);
        if (j + 1 < n && heights[i][j + 1] >= heights[i][j]) dfs(heights, i, j + 1, visited);
        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) dfs(heights, i, j - 1, visited);
        
    }
    
    
};