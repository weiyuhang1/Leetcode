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
    //0 covered, 1 has monitor, 2 uncovered
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (postorder(root) == 2) result++;
        return result;
    }
private:
    int result;
    int postorder(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = postorder(root->left);
        int right = postorder(root->right);
        
        if (left == 0 && right == 0) return 2;      
        if (left == 2 || right == 2) {
            result++;
            return 1;
        }
        return 0;
    }
    
    
};