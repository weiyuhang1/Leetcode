class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for (bool v : visited) {
            if (v == false) return false;
        }
        return true;
    }
private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int key) {
        if (visited[key] == true) {
            return;
        } else {
            vector<int> keys = rooms[key];
            visited[key] = true;
            for (int key : keys) {
                dfs(rooms, visited, key);
            }
        }
    }
    
};