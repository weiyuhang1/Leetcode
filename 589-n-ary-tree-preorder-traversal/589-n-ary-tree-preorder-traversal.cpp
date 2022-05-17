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
    vector<int> preorder(Node* root) {
        vector<int> result;
        traversal(root, result);
        return result;
        
    }
private:
    void traversal(Node* root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->val);
        for (auto child : root->children) {
            traversal(child, result);
        }
    }
    
};