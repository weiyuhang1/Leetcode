class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        matrix0 = matrix;
       dp = vector<vector<long>>(matrix.size() + 1, vector<long>(matrix[0].size() + 1, 0));
        for (long i = 1; i < dp.size(); i++) {
            for (long j = 1; j < dp[0].size(); j++) {
                dp[i][j] = -dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(long row1, long col1, long row2, long col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
        
    }
private:
    vector<vector<int>> matrix0;
    vector<vector<long>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */