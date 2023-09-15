#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
private:
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp){
        // base cases
        if(idx==nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

        int notTake =  0 + solve(idx+1, prev, nums, dp);
        int take = 0;
        if(prev==-1 || nums[idx] > nums[prev]){
            take = 1 + solve(idx+1, idx, nums, dp); 
        }


        return dp[idx][prev+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        // return solve(0, -1, nums, dp);
        int n = nums.size();
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int take = 0;
                if(j==-1 || nums[i] > nums[j]){
                    take = 1 + dp[i+1][i+1];
                }
                int notTake = dp[i+1][j+1];

                dp[i][j+1] = max(take, notTake);

            }
        }

        return dp[0][0];


        
    }
};
// @lc code=end

