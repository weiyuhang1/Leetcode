class Word {
public:
    bool isEnd;
    Word* children[26];
    Word() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};


class WordDictionary {
private:
    Word* root;
public:
    WordDictionary() {
        root = new Word(); 
    }
    
    void addWord(string word) {
        Word* cur = root;
        for (char c : word) {
            int k = c - 'a';
            if (cur->children[k] == nullptr)
                cur->children[k] = new Word();
            cur = cur->children[k];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return searchNode(word, root, 0);
    }
    bool searchNode(string& word, Word* root, int startindex) {
        Word* cur = root;
        for (int i = startindex; i < word.size() && cur; i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (searchNode(word, cur->children[j], i + 1))
                        return true;
                }
                return false;
            }
            else if (cur->children[word[i] - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[word[i] - 'a'];
        }
        return cur && cur->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */