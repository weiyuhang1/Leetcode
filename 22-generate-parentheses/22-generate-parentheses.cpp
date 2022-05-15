class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int l = n;
        int r = n;
        backtracking(l, r);
        return result;
        
    }
private:
    vector<string> result;
    string path;
    void backtracking(int l, int r) {
        if (l == 0 && r == 0) {
            result.push_back(path);
            return;
        }
        if (l > 0) {
            path.push_back('(');
            l--;
            backtracking(l, r);
            path.pop_back();
            l++;
        }
        
        if (r > l) {
            path.push_back(')');
            r--;
            backtracking(l, r);
            path.pop_back();
            r++;
        }
        
    
        
    }
    
};