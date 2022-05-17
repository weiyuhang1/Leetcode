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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> q;
        TreeNode* cur;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<double> level;            
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            double average = accumulate(level.begin(), level.end(), 0.0) / size;
            result.push_back(average);
            
        }
        return result;
        
    }
};