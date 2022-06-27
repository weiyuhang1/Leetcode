class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        const int n = s.length();
        vector<bool> visited(n, false);
        return bfs(s, dict, 0, n, visited);
    }
private:
    bool bfs(string& s, unordered_set<string>& dict, int start, int len, vector<bool>& visited) {
        if (start == s.length()) return true;
        if (visited[start]) return false;
        for (int i = 1; i <= len; i++) {
            string str = s.substr(start, i);
            if (dict.find(str) != dict.end()) {
                if (bfs(s, dict, start + i, len - i, visited)) return true;
            } else {
                continue;
            }
        }
        visited[start] = true;
        return false;
    }

};