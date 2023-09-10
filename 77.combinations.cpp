/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void solve(int index, int k, vector<int>& current, vector<vector<int>>& ans){

        // base cases
        if(k==0) {
            ans.push_back(current);
            return;
        }

        if(index<k) return;


        // notPick condition
        solve(index-1, k, current, ans);

        // pick condition

       
        current.push_back(index);
        solve(index-1, k-1, current, ans);
        current.pop_back();
        


    }
public:
    vector<vector<int>> combine(int n, int k) {

        vector<int> current;
        vector<vector<int>> ans;

        solve(n, k, current, ans);

        return ans;
        
    }
};
// @lc code=end

