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
 
    int closestValue(TreeNode* root, double target) {

   //     if (root->left == nullptr && root->right == nullptr) return root->val;
        if (target > root->val && root->right) {
                return target - root->val < abs(closestValue(root->right, target) - target) ? root->val : closestValue(root->right, target);
        } else if (target < root->val && root->left) {
                return root->val - target < abs(closestValue(root->left, target) - target) ? root-> val : closestValue(root->left, target);
        }
        return root->val;

    }
    
};