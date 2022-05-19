/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return cur;
    }
private:
    TreeNode* cur;
    int helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return 0;
        int left = helper(root->left, p, q);
        int right = helper(root->right, p, q);
        if(left == 2 || right == 2) return 2;
        int sum = 0;
        if (root == p || root == q) sum++;
        sum += left + right;
        if (sum == 2) cur = root;
        return sum;
    }
    
    
};