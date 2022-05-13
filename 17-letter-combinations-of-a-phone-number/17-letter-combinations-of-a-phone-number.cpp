class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;
        backtracking(digits, 0);
        return result;
    }
private:
    const vector<string> mp{
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"       
    };
    vector<string> result;
    string s;
    void backtracking(string& digits, int index) {
        if (s.size() == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string str = mp[digit];
        for (char c : str) {
            s.push_back(c);
            backtracking(digits, index + 1);
            s.pop_back();
        }
        
    }
    
};