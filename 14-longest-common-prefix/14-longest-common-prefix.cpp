class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        

    string result = "";
    if (strs.size() == 1) return strs[0];     
    while (true){
        for (int i = 1; i < strs.size(); i++){

            if (strs[i] == "" || strs[0] == "" || strs[i][0] != strs[0][0]) return result;
            strs[i] = strs[i].substr(1);
            
        }
        result += strs[0][0];
        strs[0] = strs[0].substr(1);
    }
    return result;
    }

};