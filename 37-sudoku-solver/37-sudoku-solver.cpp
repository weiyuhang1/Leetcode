class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
        return;
    }
private:
    bool isValid(int row, int col, char k, vector<vector<char>>& board) {
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == k) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == k) return false;
        }
        for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
            for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
                if (board[i][j] == k) return false;
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;
                            if (backtracking(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
};