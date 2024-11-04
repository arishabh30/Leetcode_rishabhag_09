#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
private:
    int solve(int i, int j, int m, int n){

        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
    
        int right = solve(i, j+1, m, n);
      
        int down = solve(i+1, j, m, n);

        return right + down;
         
    }

    int memoized(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right = memoized(i, j+1, m, n, dp);
        int down = memoized(i+1, j, m, n, dp);

        return dp[i][j] = right + down;
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        // return memoized(0, 0, m, n, dp);
        
    }
};
// @lc code=end

