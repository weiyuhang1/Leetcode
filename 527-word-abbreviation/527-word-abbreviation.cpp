class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> ans = dict;
        // sort the dict
        sort(dict.begin(), dict.end(), mycompare);
        unordered_map<string, string> mp;
        // prefix is the longest common prefix between dict[i] and dict[i-1]
        int prefix = 0; 
        for (int i = 0; i < n; ++i) {
            int j = 0;
            // j is the longest prefix length between dict[i] and dict[i+1]
           // if dict[i] is last word, or the length is different, or the last character is different, j = 0;
            if (i < n-1 && dict[i].size() == dict[i+1].size() && dict[i].back() == dict[i+1].back()) {
                while (j < dict[i].size() && dict[i][j] == dict[i+1][j])
                    j++;
            }
            if (j > prefix) prefix = j;
            // build abbreviation if it is shorter than word, and put it in a map
            if (dict[i].size() > prefix+3) {
                string s = dict[i].substr(0, prefix+1)+to_string(dict[i].size()-prefix-2)+dict[i].back();
                mp[dict[i]] = s;
            }
            // update prefix to be longest prefix with previous word
            prefix = j;
        }
        for (int i = 0; i < n; ++i) {
            if (mp.count(ans[i])) ans[i] = mp[ans[i]];
        }
        return ans;
    }
private:
    static bool mycompare(string& a, string& b) {
        if (a.size() == b.size()) {
            if (a.back() < b.back()) 
                return true;
            else if (a.back() > b.back()) 
                return false;
            for (int i = 0; i < a.size()-1; ++i) {
                if (a[i] < b[i]) 
                    return true;
                else if (a[i] > b[i])
                    return false;
            }
        }
        return a.size() < b.size();
    }
        
    
};