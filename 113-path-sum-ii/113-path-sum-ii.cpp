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
    vector<vector<int>> paths;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        findPath(root, targetSum);
        return paths;
    }
private:
    void findPath(TreeNode* root, int targetSum) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum)
            paths.push_back(path);
        findPath(root->left, targetSum - root->val);
        findPath(root->right, targetSum - root->val);
        path.pop_back();
    }
};