class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int number_of_rotten_oranges = 0;
        int number_of_fresh_oranges = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    number_of_rotten_oranges++;
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    number_of_fresh_oranges++;
                }
            }
        }
        
     
        if (number_of_fresh_oranges == 0) return 0;
        
        //start rotten nearby fresh oranges
        int minute = 0;
        int number_of_fresh_oranges_begin;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                sz--;
                number_of_fresh_oranges_begin = number_of_fresh_oranges;
                if (i + 1 < m && grid[i + 1][j] == 1) {
                    q.push({i + 1, j});
                    number_of_fresh_oranges--;
                    grid[i + 1][j] = 2;
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    q.push({i - 1, j});
                    number_of_fresh_oranges--;
                    grid[i - 1][j] = 2;
                }
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    q.push({i, j + 1});
                    number_of_fresh_oranges--;
                    grid[i][j + 1] = 2;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    q.push({i, j - 1});
                    number_of_fresh_oranges--;
                    grid[i][j - 1] = 2;
                }
                
               
                
            }
             minute++;
        }

        return number_of_fresh_oranges == 0 ? minute - 1 : -1;
        
        
        
        
    }

    
    
};