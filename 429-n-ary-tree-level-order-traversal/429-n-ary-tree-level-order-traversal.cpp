/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        Node* cur;
        queue<Node*> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (auto child : cur->children) {
                    if  (child != nullptr) q.push(child);
                }
            }
            result.push_back(level);
        }
        return result;
        
    }
};