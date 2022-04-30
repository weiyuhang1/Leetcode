class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row1 = {1};
        if (rowIndex == 0) return row1;
        
        
        
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> row2(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row2[j] = row1[j - 1] + row1[j];
            }
            row1 = move(row2);
            
        }
        return row1;
        
        
    }
};