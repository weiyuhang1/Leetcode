class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<int> directions{-1, 0, 1, 0, -1};
        int number_of_fresh_oranges = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
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
                for (int k = 1; k < directions.size(); k++) {
                    int row = i + directions[k];
                    int col = j + directions[k - 1];
                    if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
                        q.push({row, col});
                        number_of_fresh_oranges--;
                        grid[row][col] = 2;
                    }
                }
         
            }
             minute++;
        }

        return number_of_fresh_oranges == 0 ? minute - 1 : -1;
        
        
        
        
    }

    
    
};