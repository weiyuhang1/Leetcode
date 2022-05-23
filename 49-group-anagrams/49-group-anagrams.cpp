class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            mp[strSort(strs[i])].push_back(strs[i]);
        }
        
        for (auto p : mp) {
            result.push_back(p.second);
        }


        
        return result;
    }
private:
    string strSort(string s) {
        vector<char> count(26, 0);
        for (const char& c : s) {
                count[c - 'a']++;
        }
        string result;
        for (int i = 0; i < count.size(); i++) {
            result += string(count[i], i + 'a');
        }
        return result;
    }
    
};