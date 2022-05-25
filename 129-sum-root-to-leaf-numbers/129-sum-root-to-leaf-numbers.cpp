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
    int sumNumbers(TreeNode* root) {
        backtracking(root);
        return result;
    }
private:
    int path = 0;
    int result = 0;
    void backtracking(TreeNode* root) {
        if (root == nullptr) return;
        path = path* 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            result += path;
        backtracking(root->left);
        backtracking(root->right);
        path = (path - root->val) / 10;
    }
    
    
};