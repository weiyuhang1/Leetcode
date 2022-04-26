class Solution {
public:
    int strStr(string haystack, string needle) {
        int fastindex = 0;
        int slowindex = 0;
        int result = -1;
        int j = 0;
        while (slowindex < haystack.length()){
            if (j == needle.length()) return slowindex;
            
            
            
            if (haystack[fastindex] == needle[j]){
                fastindex++;
                j++;
            }else{
                slowindex++;
                fastindex = slowindex;

                j = 0;
            }
        }
        return result;
    }
};