class Solution {
public:
    int totalNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, 0);
        return count;
        
        
        
    }
private:
    int count = 0;
    void backtracking(vector<string>& chessboard, int row) {
        if (row == chessboard.size()) {
            count++;
            return;
        }
        for (int j = 0; j < chessboard.size(); j++) {
            if (chessboard[row][j] == '.' && 
                isValid(row, j, chessboard)) {
                chessboard[row][j] = 'Q';
                backtracking(chessboard, row + 1);
                chessboard[row][j] = '.';
            }
        }
    }
    bool isValid(int row, int col, vector<string>& chessboard) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >=0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < chessboard.size(); i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true;
    }
    
    
    
};