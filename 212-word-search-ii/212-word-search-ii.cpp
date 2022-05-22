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
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        root = new TrieNode();
        for (string& word : words)
            insert(root, word);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtracking(board, i, j, used, root);
            }
        }
        return result;
    }
private:
    TrieNode* root;
    string path;
    vector<string> result;
    void backtracking(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& used, TrieNode* root) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || used[i][j] == true 
           || root->children[board[i][j] - 'a'] == nullptr) return;
        path += board[i][j];
        used[i][j] = true;
        root = root->children[board[i][j] - 'a'];
        if (root->isEnd == true) {
            result.push_back(path); //needs path -=
            root->isEnd = false;
        }
        
        backtracking(board, i - 1, j, used, root);
        backtracking(board, i + 1, j, used, root);
        backtracking(board, i, j - 1, used, root);
        backtracking(board, i, j + 1, used, root);
        path.pop_back();
        used[i][j] = false;
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
    bool searchPrefix(TrieNode* root, string& prefix) {  
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (cur->children[prefix[i] - 'a'] == nullptr) return false;
            cur = cur->children[prefix[i] - 'a'];
        }
        return true;
    }
    bool searchWord(TrieNode* root, string& word) {  
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i] - 'a'] == nullptr) return false;
            cur = cur->children[word[i] - 'a'];
        }
        return cur->isEnd;
    }
    
    
    
};