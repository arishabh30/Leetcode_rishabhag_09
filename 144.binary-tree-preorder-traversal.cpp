/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    void preorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        stack<TreeNode*> st;
        while(true){
            if(root!=NULL){
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            }            
            else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                root=root->right;
            }
        }

        return ans;
    }
};
// @lc code=end

