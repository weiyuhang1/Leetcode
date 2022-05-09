class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> frequency(26, 0);
        for (int i = 0; i < s.length(); i++){
            frequency[s[i] - 'a']++;
        }
        int oddchar = 0;
        for (int i : frequency) {
            if (i % 2 == 1)
                oddchar++;
        }
        return oddchar <= 1;
    }
};