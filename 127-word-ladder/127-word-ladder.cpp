class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set s(wordList.begin(), wordList.end());
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
            }  
        }
        return 0;    
    }
};