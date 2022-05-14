class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
    
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(string& s, int startindex) {
        if (startindex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i < s.size(); i++) {
            string str = s.substr(startindex, i - startindex + 1);
            if (isPalindrome(str)) {

            path.push_back(str);
            backtracking(s, i + 1);
            path.pop_back();
            } else {
                continue;
            }
        }
    }

    bool isPalindrome(string& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
                
    
};