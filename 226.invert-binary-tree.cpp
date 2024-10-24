/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
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
private:
    void dfs(TreeNode* root){

        if(!root) return;

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        
        dfs(root->left);
        dfs(root->right);

    }
public:
    TreeNode* invertTree(TreeNode* root) {

        dfs(root);

        return root;
        
    }
};
// @lc code=end

