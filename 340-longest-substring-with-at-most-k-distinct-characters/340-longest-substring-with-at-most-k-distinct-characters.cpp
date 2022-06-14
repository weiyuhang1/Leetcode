class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int maxlen = INT_MIN;
        int i, j;
        for (i = 0, j = 0; j < s.length(); j++) {
            if (mp.size() < k || mp.find(s[j]) != mp.end()) {
                mp[s[j]] = j;
            } else {
                    char c;
                    int pos = INT_MAX;
                    mp[s[j]] = j;
                    for (auto it : mp) {
                        if (it.second < pos) {
                            pos = it.second;
                            c = it.first;
                        }
                    }
                    i = pos + 1;
                    mp.erase(c);

           
            }
                                maxlen = max(maxlen, j - i + 1);
        }
        
        if (i == 0) maxlen = s.length();
        return maxlen;
    }
}; 