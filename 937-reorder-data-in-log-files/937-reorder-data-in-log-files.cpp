class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), comp);
        return logs;
    }
private:
    static bool comp(string s1, string s2) {
        istringstream ss(s1);
        string word;
        vector<string> v1;
        while (ss >> word) {
            v1.push_back(word);
        }
        
        istringstream ss2(s2);
        vector<string> v2;
        while (ss2 >> word) {
            v2.push_back(word);
        }
        
        char c1 = v1[1][0];
        char c2 = v2[1][0];
        if (isdigit(c1) && isalpha(c2)) return false;
        if (isalpha(c1) && isdigit(c2)) return true;
        if (isalpha(c1) && isalpha(c2)) {
            if (v1.size() == v2.size() && equal(v1.begin() + 1, v1.end(), v2.begin() + 1)) {
                return v1[0] < v2[0];
            } else {
                return lexicographical_compare(v1.begin() + 1, v1.end(), v2.begin() + 1, v2.end());
            }
        }
        
        
        return false;
    }
    
    
};