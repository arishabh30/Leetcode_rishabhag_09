/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    void dfs(TreeNode* root, int row, int col, map<int, map<int, multiset<int>>>& mp){
        if(root==nullptr) return;

        mp[col][row].insert(root->val);

        dfs(root->left, row+1, col-1, mp);
        dfs(root->right, row+1, col+1, mp);
    }   
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;

        map<int, map<int, multiset<int>>> mp;

        dfs(root, 0, 0, mp);

        for(auto it : mp){
            vector<int> ans;

            for(auto itr : it.second){
                ans.insert(ans.end(), itr.second.begin(), itr.second.end());
            }

            res.push_back(ans);
        }

        return res;
    }
};
// @lc code=end

