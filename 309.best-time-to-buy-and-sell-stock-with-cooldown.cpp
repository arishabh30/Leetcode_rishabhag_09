#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
private:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        // base cases
        if(idx>=prices.size()) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy]; 

        long profit;
        if(buy==0){
            profit = max(solve(idx+1, 0, prices, dp), -prices[idx] + solve(idx+1, 1, prices, dp));
        }
        if(buy==1){
            profit = max(solve(idx+1, 1, prices, dp), prices[idx] + solve(idx+2, 0, prices, dp));
        }

        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // return solve(0,0,prices, dp);

        vector<vector<int>> dp(n+2, vector<int>(2,0));
        long profit = 0;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==0){
                    profit = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
                }
                if(j==1){
                    profit = max(dp[i+1][1], prices[i] + dp[i+2][0]);
                }

                dp[i][j] = profit;
            }
        }

        return dp[0][0];
        
    }
};
// @lc code=end

