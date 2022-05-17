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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return nullptr;
        //root node
        TreeNode* root = new TreeNode(postorder.back());
        if (postorder.size() == 1) return root;
     //   postorder.resize(postorder.size() - 1);
        int index;
        for (int i = 0; i< inorder.size(); i++) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());
        
        vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size());
        vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end() - 1);
        root->left = buildTree(leftinorder, leftpostorder);
        root->right = buildTree(rightinorder, rightpostorder);
        return root;
        
    }
};