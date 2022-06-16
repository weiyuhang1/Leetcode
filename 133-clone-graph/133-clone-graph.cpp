/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        return dfs(node);    
    }
private:
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node) {
        Node* nodecopy = new Node(node->val);
        mp[node] = nodecopy;
        for (Node* it : node->neighbors) {
            if (mp.find(it) != mp.end()) {
                nodecopy->neighbors.push_back(mp[it]);
            } else {
                nodecopy->neighbors.push_back(dfs(it));
            }
        }
        return nodecopy;
        
        
    }
    
    
};