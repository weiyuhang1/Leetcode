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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr || (!root->left && !root->right))
            return root;
        TreeNode* leftroot = upsideDownBinaryTree(root->left);
        TreeNode* rightmost = root->left;        
        rightmost->right = root;
        
        rightmost->left = root->right;
        root->left = nullptr;
        root->right= nullptr;
        
        return leftroot;
        
        
    }
};