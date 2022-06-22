class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const vector<int>& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }
        //0 unvisited 1 visiting 2 visited
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, graph, visited)) return {};
        }
     //   reverse(result.begin(), result.end());
        return result;
        
    }
private:
    vector<int> result;
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[i] == 1) return true;
        if (visited[i] == 2) return false;
        visited[i] = 1;
       
        for (int k : graph[i]) {
            if (dfs(k, graph, visited)) return true;
        }
        result.push_back(i);
        visited[i] = 2;
        
       
        return false;
    }
    
    
};