class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int maxlen = 0;
        int cur = -1;
        for (int i = 0; i < s.length(); i++) {
            if (dict.find(s[i]) == dict.end()) {
                dict[s[i]] = i;
            } else {
                if (dict[s[i]] > cur) {
                    cur = dict[s[i]];
                }
                dict[s[i]] = i;
                
                
            }
            maxlen = max(maxlen, i - cur);
        }
        return maxlen;
    }
};