class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];
    
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            if (cur->children[c] == nullptr)
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) return false;
            cur = cur->children[i];
        }
        return cur->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) return false;
            cur = cur->children[i];
        }
        return true;
    }
    
private:
    TrieNode* root;
    
    
    
};





/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */