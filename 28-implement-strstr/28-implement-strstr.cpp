class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        preprocessKMP(needle, lps);
        for (int i = 0, j = 0; i < haystack.size(); ) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            
                if (j == needle.size())
                 return i - j;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            } 
        }
        return -1;
    }
private:
    
    void preprocessKMP(string& needle, vector<int>& lps) {
        int len = 0;
        for (int i = 1; i < lps.size(); ) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                    
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
    }
    
    
};