class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> Ocells(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0, Ocells);
            dfs(board, i, n - 1, Ocells);
        }
        for (int j = 1; j < n - 1; j++) {
            dfs(board, 0, j, Ocells);
            dfs(board, m - 1, j, Ocells);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Ocells[i][j] == true) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
private:

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& Ocells) {
                const int m = board.size();
        const int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (Ocells[i][j] == true) return;
        if (board[i][j] == 'X') return;
        Ocells[i][j] = true;
        dfs(board, i + 1, j, Ocells);
        dfs(board, i - 1, j, Ocells);
        dfs(board, i, j + 1, Ocells);
        dfs(board, i , j - 1, Ocells);
            
    }
    
    
};