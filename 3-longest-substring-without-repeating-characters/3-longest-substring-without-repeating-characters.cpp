class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int cur = -1;
        int len = 0;
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
            } else {
                if (mp[s[i]] > cur)
                    cur = mp[s[i]];
                mp[s[i]] = i;
            }
            len = i - cur;
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};