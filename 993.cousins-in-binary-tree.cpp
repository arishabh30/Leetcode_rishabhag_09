#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    void dfs(TreeNode* node, int x, int y, int &x_par, int &y_par, int &x_depth, int &y_depth, int curr_depth, int curr_val){
        if(node==NULL) return;

        if(node->val == x){
            x_depth = curr_depth;
            x_par = curr_val;
            return;
        }

        if(node->val == y){
            y_depth = curr_depth;
            y_par = curr_val;
            return;
        }

        dfs(node->left, x, y, x_par, y_par, x_depth, y_depth, curr_depth+1, node->val);
        dfs(node->right, x, y, x_par, y_par, x_depth, y_depth, curr_depth+1, node->val);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int x_par, y_par, x_depth, y_depth;

        if(root==NULL) return false;

        dfs(root, x, y, x_par, y_par, x_depth, y_depth, 0, 0);

        return(x_depth==y_depth && x_par!=y_par)?true:false;
        
    }
};
// @lc code=end

