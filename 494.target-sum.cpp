/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target<-1000 || target>1000) return 0;
        if(index==0){
            if(target==0 && nums[0]==0) return 2;
            if(abs(target) == nums[0]) return 1;
            else return 0;
        }

        if(dp[index][target + 1000]!=-1) return dp[index][target+1000];

        // use -ve sign i.e., add to the target
        int add = solve(index-1, target + nums[index] , nums, dp);
        int subtract = solve(index-1, target - nums[index], nums, dp);

        return dp[index][target + 1000] = add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        vector<vector<int>> dp(nums.size()+1, vector<int>(2001, -1));

        return solve(nums.size()-1, target, nums, dp);
        
    }
};
// @lc code=end

