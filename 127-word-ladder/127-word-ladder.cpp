class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set s(wordList.begin(), wordList.end());
        vector<bool> visited(wordList.size(), false);
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){  
            int size = q.size();
            level++;
            for (int j = 0; j < size; j++) {
                
                
                for (int i = 0; i < q.front().size(); i++) {
                    string currentword = q.front();
                    for (int j = 0; j < 26; j++) {
                        currentword[i] = 'a' + j;
                        if (s.find(currentword) != s.end()) {
                            if (currentword == endWord) return level;
                            s.erase(currentword);
                            q.push(currentword);
                        }
                            
                        
                    }
                }
                q.pop();
                
                
                /*
                for (int i = 0; i < wordList.size(); i++) {
                    if (visited[i] == false && ValidNextWord(currentword, wordList[i])) {
                        if (wordList[i] == endWord) return level;
                        visited[i] = true;
                        q.push(wordList[i]);
                    }
                }
                */
            }
            
        }
        return 0;
        
    }
private:
    bool ValidNextWord (string &currentword, string& nextword) {
        if (currentword.size() != nextword.size()) return false;
        int diff = 0;
        for (int i = 0; i < currentword.size(); i++) {
            if (currentword[i] != nextword[i]) diff++;
        }
        return diff == 1;
    }
    
};