class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int m = rooms.size();
        const int n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }
        int distance = 0;
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int sz = q.size();
            distance++;
            while (sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (auto& direction : directions) {
                    int row = i + direction[0];
                    int col = j + direction[1];
                    if (row >= 0 && row < m && col >= 0 && col < n && rooms[row][col] == INT_MAX) {
                        q.push({row, col});
                        rooms[row][col] = distance;
                    }
                }
            }
        }
    }
};