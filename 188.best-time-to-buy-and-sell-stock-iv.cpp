#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
private:
    int solve(int idx, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp){
        // base cases
        if(idx==prices.size() || cnt==0) return 0;

        if(dp[idx][buy][cnt]!=-1) return dp[idx][buy][cnt];

        long profit;
        if(buy==0){
            profit = max(solve(idx+1, 0, cnt, prices, dp),-prices[idx] + solve(idx+1, 1, cnt, prices, dp));
        }

        if(buy==1){
            profit = max(solve(idx+1, 1, cnt, prices, dp), prices[idx] + solve(idx+1, 0, cnt-1, prices, dp));
        }

        return dp[idx][buy][cnt] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        // return solve(0, 0, k, prices, dp);

        long profit = 0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int cnt = k;cnt>0;cnt--){
                    if(j==0){
                        profit = max(dp[i+1][0][cnt], -prices[i] + dp[i+1][1][cnt]);
                    }
                    if(j==1){
                        profit = max(dp[i+1][1][cnt], prices[i] + dp[i+1][0][cnt-1]);
                    }

                    dp[i][j][cnt] = profit;
                }
            }
        }
        return dp[0][0][k];
        
    }
};
// @lc code=end

