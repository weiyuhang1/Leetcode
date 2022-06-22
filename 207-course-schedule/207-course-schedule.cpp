class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const vector<int>& prerequisite : prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        // 0 unvisited 1 visiting 2 visited
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, visited, graph)) return false;
        }
        return true;
        
    }
private:
  
    bool dfs(int i, vector<int>& visited, vector<vector<int>>& graph) {
        if (visited[i] == 1) return true;
        if (visited[i] == 2) return false;
        visited[i] = 1;
        for (const int& neighbour : graph[i]) {
            if (dfs(neighbour, visited, graph)) return true;
        }
        visited[i] = 2;
        return false;
    }
    
    
    
};