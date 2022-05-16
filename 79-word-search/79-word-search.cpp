class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(), vector(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtracking(i, j, board, word, 0, used)) return true;
                }
            }
        return false;
        
    }
private:
    bool backtracking(int i, int j, vector<vector<char>>& board, string& word, int k, vector<vector<bool>>& used) {
        if (k == word.size()) return true;
        if (i >= 0 && i < board.size() && j >=0 && j < board[0].size() && board[i][j] == word[k] && used[i][j] == false) {
            used[i][j] = true;
            if (backtracking(i, j + 1, board, word, k + 1, used)) return true;
            if (backtracking(i, j - 1, board, word, k + 1, used)) return true;
            if (backtracking(i + 1, j, board, word, k + 1, used)) return true;
            if (backtracking(i - 1, j, board, word, k + 1, used)) return true;
            used[i][j] = false;          
        }
        return false;
    }
    
};