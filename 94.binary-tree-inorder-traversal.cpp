#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // stack<TreeNode*> st;

        // while(true){
        //     if(root!=NULL){
        //         st.push(root);
        //         root = root->left;
        //     }
        //     else{
        //         if(st.empty()) break;
        //         root = st.top();
        //         st.pop();
        //         ans.push_back(root->val);
        //         root = root->right;
        //     }
        // }

        // TreeNode* curr = root;

        // while(!st.empty() || curr!=NULL){
        //     while(curr){
        //         st.push(curr);
        //         curr = curr->left;
        //     }
        //     curr = st.top();
        //     st.pop();
        //     ans.push_back(curr->val);
        //     curr = curr->right;

        // }

        // USING MORRIS TRAVERSAL, using threaded BTs
        TreeNode* curr = root;

        while(curr!=NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }

                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

