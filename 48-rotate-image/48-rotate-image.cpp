class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = 0; j < matrix[0].size() / 2 + matrix[0].size() % 2; j++) {
        
        int tmp = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1- i][n - 1 - j];
        matrix[n - 1- i][n - 1 - j] = tmp;
    }}}
    

    
    
};