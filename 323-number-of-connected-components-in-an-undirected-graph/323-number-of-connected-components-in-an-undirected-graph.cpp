class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        vector<vector<int>> graph(n);
        for (const vector<int>& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) count++;
            dfs(i, graph, visited);
        }
        return count;
    }
private:
    void dfs(int i, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[i] != 0) return;
        visited[i] = 1;
        for (int k : graph[i]) {
            dfs(k, graph, visited);
        }
        visited[i] = 2;
        return;
    }
    
};