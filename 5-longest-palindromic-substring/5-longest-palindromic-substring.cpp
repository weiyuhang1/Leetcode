class Solution {
public:
    string longestPalindrome(string s) {
        int lenmax = INT_MIN;
        int start = 0, end = 0;
        for ( int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenters(s, i, i);
            int len2 = expandAroundCenters(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                lenmax = len;
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, lenmax);
    }
private:
    int expandAroundCenters(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;    
    }
    
};