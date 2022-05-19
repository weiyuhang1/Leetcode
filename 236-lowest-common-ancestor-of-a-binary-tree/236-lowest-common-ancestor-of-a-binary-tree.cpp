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
    int sum;
    int helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return 0;
        if(helper(root->left, p, q) == 2) return 2;
        if(helper(root->right, p, q) == 2) return 2;
        int sum = 0;
        if (root == p || root == q) sum++;
        sum += helper(root->left, p, q) + helper(root->right, p, q);
        if (sum == 2) cur = root;
        return sum;
    }
    
    
};