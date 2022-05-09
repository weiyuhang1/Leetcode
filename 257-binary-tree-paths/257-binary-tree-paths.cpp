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
    vector<int> nums;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        path(root, nums, paths);
        return paths;
        
        
        
    }
    
private:
    void path(TreeNode* root, vector<int>& nums, vector<string>& paths) {
        if (!root) return;
        nums.push_back(root->val);
        path(root->left, nums, paths);
        path(root->right, nums, paths);
        if (root->left == nullptr && root->right == nullptr)
            paths.push_back(format_path(nums));
        nums.pop_back();
        
    }
    
    string format_path(vector<int> nums) {
        string result;
        for (int i = 0; i < nums.size() - 1; i++) {
            result += to_string(nums[i]) + "->";
        }
        result += to_string(nums[nums.size() - 1]);
        return result;
    }
};