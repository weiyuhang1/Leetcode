class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<unordered_set<int>> graph(n);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                count++;
                if (count > 1) return false;
                if (dfs(i, graph, visited)) return false;
            }
        }
        return count == 1;
        
        
    }
private:
    bool dfs(int i, vector<unordered_set<int>>& graph, vector<bool>& visited) {
        if (visited[i]) return true;
        visited[i] = true;
        for (auto k : graph[i]) {
       //     graph[i].erase(k);
            graph[k].erase(i);
            if (dfs(k, graph, visited)) return true;
        }
        return false;
    }
    
};