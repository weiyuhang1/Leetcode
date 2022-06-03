class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        matrix0 = matrix;
       dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = dp[i][j - 1] + matrix[i][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += dp[i][col2 + 1] - dp[i][col1];
        }
        return sum;
        
    }
private:
    vector<vector<int>> matrix0;
    vector<vector<int>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */