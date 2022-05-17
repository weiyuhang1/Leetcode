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
        unordered_map<int, int> mp;
        for (int i = 0; i< inorder.size(); i++) {
            mp[inorder[i]] = i;
            }   
        return traversal(inorder, postorder, mp, 0, inorder.size(), 0, postorder.size());
        
    }
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp,
                        int inorderbegin, int inorderend, int postorderbegin, int postorderend) {
        if (postorderend == postorderbegin) return nullptr;
        //root node
        TreeNode* root = new TreeNode(postorder[postorderend - 1]);
        if (postorderend - postorderbegin == 1) return root;
     //   postorder.resize(postorder.size() - 1);
        int index = mp[root->val];
        int leftinorderbegin = inorderbegin;
        int leftinorderend = index;
        int rightinorderbegin = index + 1;
        int rightinorderend = inorderend;
        
        int leftpostorderbegin = postorderbegin;
        int leftpostorderend = postorderbegin + leftinorderend - leftinorderbegin;
        int rightpostorderbegin = leftpostorderend;
        int rightpostorderend = postorderend - 1;
        
        root->left = traversal(inorder, postorder, mp, leftinorderbegin, leftinorderend, leftpostorderbegin, leftpostorderend);
        root->right = traversal(inorder, postorder, mp, rightinorderbegin, rightinorderend, rightpostorderbegin, rightpostorderend);
        return root;
    }
    
};