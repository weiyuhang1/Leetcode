class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {};
        for (int i = 0; i < magazine.length(); i++){
            hash[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++){
            hash[ransomNote[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (hash[i] < 0) return false;
        }
        return true;
    }
};