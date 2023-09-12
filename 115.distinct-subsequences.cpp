#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
int mod = 1e9+7;
class Solution {
private:
    int solve(int ind1, int ind2, string& s, string& t, vector<vector<int>>& dp){
        // base cases
        if(ind2<0) return 1;
        if(ind1<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        // match
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2] = solve(ind1-1, ind2-1, s, t,dp) + solve(ind1-1, ind2, s, t, dp);
        }
        else{
            return dp[ind1][ind2] = solve(ind1-1, ind2, s, t, dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        // create the dp array to determine the LCS.
        int n = s.size();
        int m = t.size();

        vector<vector<int32_t>> dp(n+1, vector<int32_t>(m+1, 0));

        for(int i=0;i<=n;i++) dp[i][0] = 1;
        // for(int j=0;j<=m;j++) dp[0][j] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // match
                if(s[i-1]==t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];


        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, s, t, dp);


    }
};
// @lc code=end

