class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(), vector(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    if (backtracking(i, j, board, word, 1, used)) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
        
    }
private:
    bool backtracking(int i, int j, vector<vector<char>>& board, string& word, int k, vector<vector<bool>>& used) {
        if (k == word.size()) return true;
        if (j + 1 < board[0].size() && board[i][j + 1] == word[k] && used[i][j + 1] == false){
            used[i][j + 1] = true;
            if (backtracking(i, j + 1, board, word, k + 1, used)) return true;
            used[i][j + 1] = false;
        }
        if (j - 1 >= 0 && board[i][j - 1] == word[k] && used[i][j - 1] == false) {
            used[i][j - 1] = true;
            if (backtracking(i, j - 1, board, word, k + 1, used)) return true;
            used[i][j - 1] = false;
        }
        if (i + 1 < board.size() && board[i + 1][j] == word[k] && used[i + 1][j] == false) {
            used[i + 1][j] = true;
            if (backtracking(i + 1, j, board, word, k + 1, used)) return true;
            used[i + 1][j] = false;
        }
        if (i - 1 >= 0 && board[i - 1][j] == word[k] && used[i - 1][j] == false) {
            used[i - 1][j] = true;
            if (backtracking(i - 1, j, board, word, k + 1, used)) return true;
            used[i - 1][j] = false;
        }
        return false;
    }
    
};