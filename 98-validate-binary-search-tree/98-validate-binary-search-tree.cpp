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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        long leftmax = LONG_MIN;
        long rightmin = LONG_MAX;
        findmax(root->left, leftmax);
        findmin(root->right, rightmin);  
        return (leftmax < root->val) &&
            (rightmin > root->val) &&
            isValidBST(root->left) && isValidBST(root->right);
        
    }
private:
    void findmax(TreeNode* root, long& largest) {
        if (root == nullptr) return;
        if (root->val > largest) largest = root->val;
        findmax(root->left, largest);
        findmax(root->right, largest);
    }
    void findmin(TreeNode* root, long& smallest) {
        if (root == nullptr) return;
        if (root->val < smallest) smallest = root->val;
        findmin(root->left, smallest);
        findmin(root->right, smallest);
    }
    
    
};