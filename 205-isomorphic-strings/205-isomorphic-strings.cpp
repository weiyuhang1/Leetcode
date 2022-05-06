class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return Isomorphic(s, t) && Isomorphic(t,s);

    }
private:
    bool Isomorphic(string s, string t) {
        unordered_map<char, char> map;
        for (int i = 0; i < t.length(); i++) {
                if (map.find(s[i]) != map.end()) {
                    if (map[s[i]] != t[i]) return false;
                }else {
                    map[s[i]] = t[i];
                }
        }
        return true;
    }
    
};