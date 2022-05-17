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
    vector<int> postorder(Node* root) {
        stack<Node*> st;
        vector<int> result;
        Node* cur;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            cur = st.top();
            st.pop();
                        result.push_back(cur->val);
            for (auto child : cur->children) {
                if (child) st.push(child);
            }

        }
        reverse(result.begin(), result.end());
        return result;
    }
};