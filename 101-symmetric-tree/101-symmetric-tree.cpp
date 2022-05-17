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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* leftnode = q.front();
            q.pop();
            TreeNode* rightnode = q.front();
            q.pop();
            if (!leftnode && !rightnode) continue;
            if (!leftnode || !rightnode) return false;
            if (leftnode->val != rightnode->val) return false;
            q.push(leftnode->left);
            q.push(rightnode->right);
            q.push(leftnode->right);
            q.push(rightnode->left);
        }
        return true;
    }

};