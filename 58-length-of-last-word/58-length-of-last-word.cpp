class Solution {
public:
    int lengthOfLastWord(string s) {

        int len = 0;
        int last = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' ' && i-1 >= 0 && s[i-1] != ' '){
                last = len;
                len = 0;


            }
            if (s[i] != ' '){
                len++;
            }
        }
        if (s.back() != ' ') last = len;
        return last;
        
    }
};