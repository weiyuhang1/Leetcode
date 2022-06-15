class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsset;
        for (auto& word : words) {
            wordsset.insert(word);
        }
        int ans = 0;
        for (const string& word : words) {
            ans = max(ans, dfs(memo, wordsset, word));
        }
        return ans;
        
        
        
    }
private:
    int dfs(unordered_map<string, int>& memo, unordered_set<string>& wordsset, const string& currentword) {
        if (memo.find(currentword) != memo.end())
            return memo[currentword];
        int maxlen = 1;
        
        for (int i = 0; i < currentword.length(); i++) {
            string newword = currentword.substr(0, i).append(currentword.substr(i + 1));
            if (wordsset.find(newword) != wordsset.end()) {
                int currenlen = 1 + dfs(memo, wordsset, newword);
                maxlen = max(maxlen, currenlen);
            }
        }
        memo[currentword] = maxlen;
        return maxlen;
    }
    
    
};