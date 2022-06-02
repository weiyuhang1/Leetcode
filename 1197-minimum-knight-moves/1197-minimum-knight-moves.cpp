class Solution {
public:
    int minKnightMoves(int x, int y) {
        int step = -1;
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {-1,2}, {1,2}, {1,-2}, {-1,-2}}; 
        q.push({0, 0});
        x = abs(x);
        y = abs(y);
        while (!q.empty()) {
            int size = q.size();
            step++;
            for (int i = 0; i < size; i++) {
                int startx = q.front().first;
                int starty = q.front().second;
                q.pop();
                if (startx == x && starty == y) return step;
                for (vector<int> direction : directions) {
                    if (visited.find({startx + direction[0], starty + direction[1]}) == visited.end()
                       && startx + direction[0] >= -2 && starty + direction[1] >= -2
                       && startx + direction[0] <= x + 2 && starty + direction[1] <= y + 2){
                        visited.insert({startx + direction[0], starty + direction[1]});
                        q.push({startx + direction[0], starty + direction[1]});
                    }
                }
            }
        }

        return -1;
    }
    
};