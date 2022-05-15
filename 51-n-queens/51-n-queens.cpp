class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(0, n, chessboard);
        return result;
        
    }
private:
    
    vector<vector<string>> result;
    void backtracking(int row, int n,  vector<string>& chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n, chessboard)) {
                chessboard[row][col] = 'Q';
                backtracking(row + 1, n, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    bool isValid(int row, int col, int n, vector<string>& chessboard) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true;
    }
    
    
};