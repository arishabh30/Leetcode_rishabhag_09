#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
private:
    bool solve(int i, int j, string &s, string& p,vector<vector<int>>& dp){
        // base cases

        if(i<0 && j<0) return 1;
        if(i>=0 && j<0) return 0;
        if(i<0 && j>=0){
                while(j>=0){
                    if(p[j]!='*') return 0;
                    j--;
                }
                return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        // match
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = solve(i-1, j-1, s, p, dp);

        // not match
        
        if(p[j]=='*'){
            return dp[i][j] = solve(i-1, j, s,p, dp) || solve(i, j-1, s, p, dp);
        }
        return dp[i][j] = 0;
    }
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, s, p, dp);

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        dp[0][0] = 1;
        for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    dp[0][j] = dp[0][j-1];
                }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
               
                else if(p[j-1]=='*'){
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

