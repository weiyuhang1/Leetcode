class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n / 10 == 0) return n;
        string num = to_string(n);
        int flag = num.size();
        int i;
        for (i = num.length() - 2; i >= 0; i--) {
                if (num[i] >num [i + 1]) {
                    num[i]--;
                    flag = i + 1;
                }
        }
                for (int j = flag; j < num.length(); j++) {
                    num[j] = '9';
                }
            
        
        return stoi(num);
    }
};