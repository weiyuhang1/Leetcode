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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        TreeNode* cur;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int largestvalue = INT_MIN;
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                largestvalue = max(largestvalue, cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            result.push_back(largestvalue);
        }
        return result;
    }
};