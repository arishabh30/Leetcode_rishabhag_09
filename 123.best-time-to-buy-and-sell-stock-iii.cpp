#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
private:
    int solve(int idx, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp){
        // base cases
        if(cnt==2) return 0;
        if(idx == prices.size()) return 0;

        if(dp[idx][buy][cnt]!=-1) return dp[idx][buy][cnt];

        long profit;

        // when you can buy
        if(buy==0){
             profit = max(solve(idx+1, 0, cnt, prices, dp), -prices[idx] + solve(idx+1, 1, cnt, prices, dp));
        }
        // when you can sell
        if(buy==1){
             profit = max(solve(idx+1, 1, cnt, prices, dp), prices[idx] + solve(idx+1, 0, cnt+1, prices, dp));
        }

        return dp[idx][buy][cnt] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {

        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3,-1)));
        // return solve(0,0,0,prices, dp);

        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));


        long profit;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=2;k>0;k--){

                    if(j==0){
                        profit = max(dp[i+1][0][k], -prices[i] + dp[i+1][1][k]);
                        
                    }
                    if(j==1){
                        profit = max(dp[i+1][1][k], prices[i] + dp[i+1][0][k-1]);
                    }

                    dp[i][j][k] = profit;

                }
            }
        }

        return dp[0][0][2];
        
    }
};
// @lc code=end

