class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int up, down, left, right;
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1){
                    if (i == 0 || grid[i - 1][j] == 0) {
                        up = 0;
                    } else {
                        up = 1;
                    }
                    if (i == grid.size() - 1 || grid[i + 1][j] == 0) {
                        down = 0;
                    } else {
                        down = 1;
                    }
                    
                    if (j == 0 || grid[i][j - 1] == 0) {
                        left = 0;
                    } else {
                        left = 1;
                    }
                    if (j == grid[0].size() - 1 || grid[i][j + 1] == 0) {
                        right = 0;
                    } else {
                        right = 1;
                    }
                    result += 4 - up - down - left - right;
                    
                        
                    
                }
            }
        }
        return result;
    }
};