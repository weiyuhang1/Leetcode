class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slowIndex_s = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] != '#'){
                s[slowIndex_s] = s[i];
                slowIndex_s++;
            }else{
                if (slowIndex_s > 0)
                    slowIndex_s--;
            }
                
        }
        int slowIndex_t = 0;
        for (int i = 0; i < t.length(); i++){
            if (t[i] != '#'){
                t[slowIndex_t] = t[i];
                slowIndex_t++;
            }else{
                if (slowIndex_t > 0)
                    slowIndex_t--;
            }
                
        }
        
        if (slowIndex_s == slowIndex_t){
            for (int i = 0; i < slowIndex_s; i++){
                if (s[i] != t[i])
                    return false;
            }
            return true;
        }else return false;
        
        
    }
};