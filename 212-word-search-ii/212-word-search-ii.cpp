class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string& word : words)
            insert(root, word);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtracking(board, i, j, root);
            }
        }
        return result;
    }
private:
    TrieNode* root;
    string path;
    vector<string> result;
    void backtracking(vector<vector<char>>& board, int i, int j, TrieNode* root) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#' 
           || root->children[board[i][j] - 'a'] == nullptr) return;
        path += board[i][j];
        char c = board[i][j];
        
        root = root->children[board[i][j] - 'a'];
        board[i][j] = '#';
        if (root->isEnd == true) {
            result.push_back(path); //needs path -=
            root->isEnd = false;
        }
        
        backtracking(board, i - 1, j, root);
        backtracking(board, i + 1, j, root);
        backtracking(board, i, j - 1, root);
        backtracking(board, i, j + 1, root);
        path.pop_back();
        board[i][j] = c;
    }
    void insert(TrieNode* root, string& word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i] - 'a'] == nullptr)
                cur->children[word[i] - 'a'] = new TrieNode();
            cur = cur->children[word[i] - 'a'];
        }
        cur->isEnd = true;
    }
};