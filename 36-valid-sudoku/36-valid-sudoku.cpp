class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //checking rows
        unordered_set<char> row;
        for (int i = 0; i < board.size(); i++) {
            row.clear();
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                if (row.find(board[i][j]) == row.end()) {
                    row.insert(board[i][j]);
                } else {
                    return false;
                }
            }
        }
        
        //checking columns
        for (int j = 0; j < board[0].size(); j++) {
            row.clear();
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] == '.') continue;
                if (row.find(board[i][j]) == row.end()) {
                    row.insert(board[i][j]);
                } else {
                    return false;
                }
            }
        }
        
        //checking subboxes
        for (int k = 0; k < 9; k++) {
            int r = k / 3;
            int col = k % 3;
            row.clear();
            for (int i = 3 * r; i < 3 * r + 3; i++) {
                for (int j = 3 * col; j < 3 * col + 3; j++) {
                    if (board[i][j] == '.') continue;
                    if (row.find(board[i][j]) == row.end()) {
                        row.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
             }
        
        }
        return true;
    }
};