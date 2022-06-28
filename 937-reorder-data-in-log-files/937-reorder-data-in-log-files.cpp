class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits, result;
        vector<pair<string, string>> letters;
        for (string& s : logs) {
            int i = 0;
            while (s[i] != ' ') {
                i++;
            }
            if (isalpha(s[i + 1])) {
                letters.push_back({s.substr(0, i), s.substr(i + 1)});
            } else {
                digits.push_back(s);
            }
        }
        
        
        sort(letters.begin(), letters.end(), comp);
        for (pair<string, string>& p : letters) {
            result.push_back(p.first + " " + p.second);
        }
        for (string& s : digits) result.push_back(s);
        return result;
    }
private:
    static bool comp(pair<string, string>& s1, pair<string, string>& s2) {
        if (s1.second == s2.second) {
            return s1.first < s2.first;
        } else {
            return s1.second < s2.second;
        }
    }
        
    
};