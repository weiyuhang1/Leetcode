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
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int minimumdifference = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] < minimumdifference)
                minimumdifference = nums[i] - nums[i - 1];
        }
        return minimumdifference;
    }
private:
    vector<int> nums;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    
};