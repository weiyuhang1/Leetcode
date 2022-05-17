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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr || subRoot == nullptr) return false;
        
        //traversal of tree root
        
        
        
        if (isSametree(root, subRoot)) return true;
        if (isSubtree(root->left, subRoot)) return true;
        if (isSubtree(root->right, subRoot)) return true;
        return false;
    }
private:
    bool isSametree(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return (root1->val == root2->val && isSametree(root1->left, root2->left) &&
               isSametree(root1->right, root2->right));
    }
    
};