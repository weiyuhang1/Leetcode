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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
private:
    TreeNode* pre = nullptr;
    vector<int> result;
    int count = 0;
    int maxcount = INT_MIN;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (pre == nullptr) {
            pre = root;
            count = 1;
        } else if (root->val == pre->val) {
            count++;
        } else {
            count = 1;
            pre = root;
        }
        
        if (count > maxcount) {
            result.clear();
            result.push_back(root->val);
            maxcount = count;
        } else if (count == maxcount) {
            result.push_back(root->val);
        }
        
        
        inorder(root->right);
        return;
        
    }
    
};