class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        const int n = points.size();
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({distance, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        
      
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int sum = 0;
        int count = 0;
        for (auto& edge : edges) {
            if (Union(edge[1], edge[2])) {
                sum += edge[0];
                count++;
            }
            
            if (count == n - 1) return sum;
            
        }
        return -1;
        
        
    }
private:
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }
    bool Union(int p1, int p2) {
        int parent1 = find(p1);
        int parent2 = find(p2);
        if (parent1 == parent2) return false;  //already in the same tree
        parent[parent1] = p2;
        return true;
    }
    
};