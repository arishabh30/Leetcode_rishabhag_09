#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
private:
    int solve(int ind1, int buy, vector<int>& prices, vector<vector<int>>& dp){
        // base cases
        if(ind1==prices.size()) return 0;

        if(dp[ind1][buy] != -1) return dp[ind1][buy];
        int profit;
        if(buy==0){
            profit = max(0 + solve(ind1+1, 0, prices, dp), -prices[ind1] + solve(ind1+1, 1, prices, dp));
        }

        if(buy==1){
            profit = max(0 + solve(ind1+1, 1, prices, dp), prices[ind1] + solve(ind1+1, 0, prices, dp));
        }

        return dp[ind1][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {


        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        // return solve(0, 0, prices, dp);

        int n = prices.size();

        vector<vector<long>> dp(n+1, vector<long>(2,-1));
        dp[n][0] = 0;
        dp[n][1] = 0;

        long profit;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==0){
                    profit = max(dp[i+1][0], -prices[i]+dp[i+1][1]);
                }
                if(j==1){
                    profit = max(dp[i+1][1], prices[i] + dp[i+1][0]);
                }

                dp[i][j] = profit;
            }
            
        }

        return dp[0][0];
        
    }
};
// @lc code=end

