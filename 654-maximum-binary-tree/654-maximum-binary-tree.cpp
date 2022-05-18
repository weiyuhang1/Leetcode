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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
private:
    TreeNode* helper(vector<int>& nums, int arraybegin, int arrayend) {
        if (arraybegin >= arrayend) return nullptr;
        int maxelement = INT_MIN;
        int index;
        for (int i = arraybegin; i < arrayend; i++) {
            if (nums[i] > maxelement) {
                maxelement = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(maxelement);
        root->left = helper(nums, arraybegin, index);
        root->right = helper(nums, index + 1, arrayend);
        return root;
    }
    
    
};