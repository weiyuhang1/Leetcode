class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int len = 0;
        int maxlen = 0;
        int cur = -1;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]] = i;
            } else {
                if (mp.size() < 2) {
                    mp[s[i]] = i;
                } else {
                    auto it = mp.begin();
                    it++;
                    if (mp.begin()->second < it->second) {
                        cur = mp.begin()->second;
                        mp.erase(mp.begin());
                        mp[s[i]] = i;
                    } else {
                        cur = it->second;
                        mp.erase(it);
                        mp[s[i]] = i;
                    }
                }
            }
            len = i - cur;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};