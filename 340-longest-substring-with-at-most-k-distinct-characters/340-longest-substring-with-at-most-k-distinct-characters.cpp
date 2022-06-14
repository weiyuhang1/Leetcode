class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int maxlen = INT_MIN;
        int i, j;
        for (i = 0, j = 0; j < s.length(); j++) {
            mp[s[j]]++;
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        
    //    if (i == 0) maxlen = s.length();
        return maxlen;
    }
}; 