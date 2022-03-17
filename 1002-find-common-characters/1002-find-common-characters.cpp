class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        if (words.size() == 0) return result;
        int hash[26] = {};
        for (char c : words[0]){
            hash[c - 'a']++;
        }
        
        int hashnext[26] = {};
        for (int i = 1; i < words.size(); i++){
            memset(hashnext, 0 ,26*sizeof(int));
        
            for (char c : words[i]){
                hashnext[c - 'a']++;
            
            }
            for (int k = 0 ; k < 26; k++){
                hash[k] = min(hash[k], hashnext[k]);
            }
        }
        
        for (int i = 0; i < 26; i++){
            while (hash[i] != 0){
                string s(1, i + 'a');
                result.push_back(s);
                hash[i]--;
            }
        }
        return result;
    }
};