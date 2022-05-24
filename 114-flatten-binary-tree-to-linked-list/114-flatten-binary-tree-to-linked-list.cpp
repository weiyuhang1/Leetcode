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
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
private:
    TreeNode* flattenTree(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;
        
        TreeNode* lefttail = flattenTree(root->left);
        TreeNode* righttail = flattenTree(root->right);
        
        if (lefttail != nullptr) {
            lefttail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        return righttail == nullptr ? lefttail : righttail;
        
        
    }
    
    
};