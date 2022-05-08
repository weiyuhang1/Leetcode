class Solution {
public:
    bool isStrobogrammatic(string num) {
        for (int i = 0; i < num.length(); i++) {
            if (!helper(num[i], num[num.length() - 1 - i]))
                return false;
        }
        return true;
        
    }
private:
    bool helper(char a, char b) {
        
        if ((a == '0' && b == '0') ||
            (a == '1' && b == '1') ||
            (a == '6' && b == '9') ||
            (a == '8' && b == '8') ||
            (a == '9' && b == '6')) {
            return true;
        }
        return false;
    }

    
};