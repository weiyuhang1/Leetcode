class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
   //     vector<string> p(26,"!!");
        unordered_map<char, string> mp;
        unordered_set<string> set;
        
        if (pattern.length() != words.size()) return false;
        
        for (int i = 0; i < pattern.size(); i++) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (set.count(words[i]) > 0) return false;
                mp[pattern[i]] = words[i];
                set.insert(words[i]);
            } else if (mp[pattern[i]] != words[i]) {
                return false;
            }
                
        }
   /*     
        unordered_map<string, char> mp1;
        for (int i = 0; i < s.length(); i++) {
            if (mp1.find(words[i]) != mp1.end()) {
                mp1[words[i]] = pattern[i];
            } else if (mp1[words[i]] != pattern[i]) {
                return false;
            }
                
        }
        */
        
        
        return true;
        
    }
};