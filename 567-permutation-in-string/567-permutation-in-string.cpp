class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        const int k = s1.length();
        vector<int> mp(26, 0);
        for (char c : s1) {
            mp[c - 'a']++;
        }
        int count = 0;
        vector<int> mp2(26, 0);
        for (int left = 0; left < s1.length(); left++) {
            mp2[s2[left] - 'a']++;
        }
        if (isValid(mp, mp2)) return true;
        
        for (int left = 1; left <= s2.length() - s1.length(); left++) {
            mp2[s2[left + k - 1] - 'a']++;
            mp2[s2[left - 1] - 'a']--;
            if (isValid(mp, mp2)) return true;
        }
        return false;
    }
private:
    bool isValid(vector<int>& vect, vector<int>& vect2) {
        for (int i = 0; i < vect.size(); i++) {
            if (vect[i] != vect2[i]) return false;
        }
        return true;
    }
                  
                   
                   
};