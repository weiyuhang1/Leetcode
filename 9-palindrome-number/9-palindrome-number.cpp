class Solution {
public:
    bool isPalindrome(int x) {
/*        string s = to_string(x);
        for (int i = 0; i < s.length()/2; i++){
            if (s[i] != s[s.length() - i - 1]) return false;
        }
        return true;*/
        
        if (x < 0 || (x != 0 && x % 10 ==0)) return false;
        
        int revhalf = 0;
        while (x > revhalf) {
            revhalf = revhalf * 10 + x % 10;
            x /= 10;
        }
        
        return x == revhalf || x == revhalf /10;
        
    }
};