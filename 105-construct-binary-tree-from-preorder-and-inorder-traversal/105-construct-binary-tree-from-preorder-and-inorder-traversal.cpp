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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return traversal(preorder, inorder, mp, 0, preorder.size(), 0, inorder.size());
        
    }
private:
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mp,
                       int preorderbegin, int preorderend, int inorderbegin, int inorderend) {
        if (preorderend == preorderbegin) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderbegin]);
        if (preorderend - preorderbegin == 1) return root;
        
        //finds the index of the root value in the inorder vector
        int index = mp[root->val];
        int leftinorderbegin = inorderbegin;
        int leftinorderend = index;
        int rightinorderbegin = index + 1;
        int rightinorderend = inorderend;
        
        int leftpreorderbegin = preorderbegin + 1;
        int leftpreorderend = preorderbegin + 1 + leftinorderend - leftinorderbegin;
        int rightpreorderbegin = leftpreorderend;
        int rightpreorderend = preorderend;
        
        root->left = traversal(preorder, inorder, mp, leftpreorderbegin, leftpreorderend, leftinorderbegin, leftinorderend);
        root->right = traversal(preorder, inorder, mp, rightpreorderbegin, rightpreorderend, rightinorderbegin, rightinorderend);
        return root;
    }
    
};