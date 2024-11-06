/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    void postorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // postorder(root, ans);
        // stack<TreeNode*> st;
        // if(root==NULL) return {};
        // st.push(root);

        // while(!st.empty()){
        //     TreeNode* curr = st.top();
        //     st.pop();
        //     ans.push_back(curr->val);

        //     if(curr->left) st.push(curr->left);
        //     if(curr->right) st.push(curr->right);
        // }

        // reverse(ans.begin(), ans.end());

        // return ans;

        if(root==NULL) return {};
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        bool isVisited = false;

        while(!st.empty()){
            auto p = st.top();
            TreeNode* node = p.first;
            bool isVisited = p.second;

            if(!isVisited){
                st.top().second = true;
                if(node->right){
                    st.push({node->right, false});
                }
                if(node->left){
                    st.push({node->left, false});
                }
            }
            else{
                st.pop();
                ans.push_back(node->val);
            }
        }

        return ans;
    }
};
// @lc code=end

