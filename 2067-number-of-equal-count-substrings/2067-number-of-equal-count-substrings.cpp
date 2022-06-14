class Solution {
public:
    int equalCountSubstrings(string s, int count) {
     //   const int maxunique = unordered_set<char>(s.begin(), s.end()).size();
        
        const int n = s.length();
        int times = 0;
        for (int uniquechar = 1; uniquechar * count <= n && uniquechar <= 26; uniquechar++) {
            unordered_map<char, int> mp;
            int len = uniquechar * count;
            for (int j = 0; j < n; j++) {
                mp[s[j]]++;
                if (j > len - 1) {
                    int i = j - len;
                    mp[s[i]]--;
                    if (mp[s[i]] <= 0) mp.erase(s[i]);
              
                }
                if (isValid(mp, count) && mp.size() == uniquechar) times++;
            
            }
            
            
        }
        return times;
        
        
        
    }
private:
    bool isValid(unordered_map<char, int>& mp, int count) {
        for (auto pair : mp) {
            if (pair.second != count && pair.second != 0) return false;
        }
        return true;
    }
    
    
};