/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    void dfs(TreeNode* root, int level, vector<int>& ans){
        if(root==NULL) return;

        if(ans.size() == level) ans.push_back(root->val);

        dfs(root->right, level+1, ans);
        dfs(root->left, level+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {

        // bfs approach
        
        // vector<int> ans;

        // if(root==NULL) return {};
        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()){
            
        //     int size = q.size();
        //     for(int i =0; i<size; i++){
        //         TreeNode* node = q.front();
        //         q.pop();

        //         if(i==size-1) ans.push_back(node->val);

        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        // }

        // return ans;

        // DFS approach

        vector<int> ans;

        dfs(root, 0, ans);

        return ans;
    }
};
// @lc code=end

