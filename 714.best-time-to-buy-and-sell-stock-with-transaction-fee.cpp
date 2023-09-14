#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
private:
    int solve(int idx, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp){
        // base cases
        if(idx==prices.size()) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        long profit;
        if(buy==0){
            profit = max(solve(idx+1, 0, fee, prices, dp),-prices[idx] + solve(idx+1, 1, fee, prices, dp)); 
        }

        if(buy==1){
            profit = max(solve(idx+1, 1, fee, prices, dp), prices[idx] + solve(idx+1, 0, fee, prices, dp) - fee);
        }

        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0,0,fee,prices, dp);
        
    }
};
// @lc code=end

