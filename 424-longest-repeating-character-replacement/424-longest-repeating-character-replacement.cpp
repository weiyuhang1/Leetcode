class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int result = 0;
        int start = 0;
        int maxcount = 0;
        for (int end = 0; end < s.size(); end++) {
            count[s[end] - 'A']++;
            maxcount = max(maxcount, count[s[end] - 'A']);
            while (end - start + 1 - maxcount > k) {
              
                count[s[start] - 'A']--;
                start++;
          //      maxcount = 0;
                for (int i = 0; i < count.size(); i++) {
                    if (count[i] > maxcount) maxcount = count[i];
                }
                
                
            }
            result = max(result, end - start + 1);
        }
        return result;
    }
};