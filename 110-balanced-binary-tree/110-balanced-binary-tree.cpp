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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
            abs(maxDepth(root->left) - maxDepth(root->right)) <=1;
        
        
    }
    
    //minDepth couldn't guarantee left subtree and right subtree is balanced
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};