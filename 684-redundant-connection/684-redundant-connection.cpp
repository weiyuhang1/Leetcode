class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for (vector<int> edge : edges) {
            if (sameSet(edge[0], edge[1])) {
                return edge;
            } else {
                unionSet(edge[0], edge[1]);
            }
        }
        return edges[0];
    }
private:
    vector<int> parent;
    int find(int i) {
        while (parent[i] != i) {
            i = parent[i];
        }
        return i;
    }
    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }
    void unionSet(int u, int v) {
        parent[find(u)] = parent[v]; //make root of u child of root of v;
    }
    
    
    
    
};