class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int offset = 1;
        int count = 1;
        int loopnum = n/2;
        int startx = 0;
        int starty = 0;
        while (loopnum) {
            
            i = startx;
        for (j = starty; j < n - offset; j++) {
            res[i][j] = count;
            count++;
        }
        
        for (i = startx; i < n- offset; i++) {
            res[i][j] = count;
            count++;
        }
        
        for (; j > offset - 1; j--) {
            res[i][j] = count;
            count++;
        }
        
        for (; i > offset - 1; i--) {
            res[i][j] = count;
            count++;
                
        }
            startx++;
            starty++;
            
            offset += 1;
            loopnum--;
        }
        
        if (n % 2 == 1)
            res[n/2][n/2] = count;
        
        return res;
        
    }
};