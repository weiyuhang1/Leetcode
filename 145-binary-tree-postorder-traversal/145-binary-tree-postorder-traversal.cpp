/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        if (root == nullptr) return nodes;
        TreeNode* cur;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            nodes.push_back(cur->val);
            
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        reverse(nodes.begin(), nodes.end());
        return nodes;
    }
};