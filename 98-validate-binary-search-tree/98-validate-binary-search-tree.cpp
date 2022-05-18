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
        inorder(root);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) return false;
        }
        return true;
    }
private:
    vector<int> nums;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    
};