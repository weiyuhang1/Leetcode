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
        TreeNode* rightmost = leftroot;
        while (rightmost->right) {
            rightmost = rightmost->right;
        }
        
        
        rightmost->right = root;
        
        rightmost->left = root->right;
        root->left = nullptr;
        root->right= nullptr;
        if (rightmost->left) {
            rightmost->left->left = nullptr;
            rightmost->left->right = nullptr;
        }
        
        return leftroot;
        
        
    }
};