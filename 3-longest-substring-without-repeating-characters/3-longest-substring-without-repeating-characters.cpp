class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1) return 1;
        unordered_map<char, int> mp;
        int len = 0;
        int lenmax = 0;
        int cur = -1;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;


            } else {
                if (mp[s[i]] > cur)
                    cur = mp[s[i]];
                mp[s[i]] = i;                       
                

            }
            len = i - cur;
            lenmax = max(len, lenmax);
        }
     
        return lenmax;
        
        
    }
};