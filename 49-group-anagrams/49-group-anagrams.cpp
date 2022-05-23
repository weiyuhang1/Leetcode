class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> matrix(strs.size(), vector(27, 0));
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            for (const char& c : strs[i]) {
                matrix[i][c - 'a']++;
            }
            matrix[i][26] = 1;
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][26] == 0) continue;
            vector<string> path{strs[i]};
            for (int j = i + 1; j < matrix.size(); j++) {
                if (matrix[j][26] == 0 || strs[j].size() != strs[i].size()) continue;
                if (matrix[j] == matrix[i]) {
                    path.push_back(strs[j]);
                    matrix[j][26] = 0;
                }
            }
            matrix[i][26] = 0;
            result.push_back(path);
        }
        
        return result;
    }
};