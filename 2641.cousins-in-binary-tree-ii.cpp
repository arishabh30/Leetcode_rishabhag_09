#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        if(!root) return root;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;

        while(!q.empty()){
            int size = q.size();
            int temp = 0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                temp+=node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }

            levelSum.push_back(temp);
        }

        root->val = 0;
        q.push(root);
        int level = 1;

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                int siblingSum = (node->left? node->left->val : 0) + (node->right? node->right->val : 0);

                if(node->left){
                    node->left->val = levelSum[level] - siblingSum;
                    q.push(node->left);
                }

                if(node->right){
                    node->right->val = levelSum[level] - siblingSum;
                    q.push(node->right);
                }
            }

            level++;
        }

        return root;
        
    }
};
// @lc code=end

