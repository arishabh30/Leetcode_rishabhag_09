#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
private:
    int solve(int index1, int index2, string& text1, string& text2, vector<vector<int>>& dp){
        // base cases

        if(index1<0 || index2<0) return 0;

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        // match condition
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + solve(index1-1, index2-1, text1, text2, dp);
        }

        // not match condition
        return dp[index1][index2] = max(solve(index1-1, index2, text1, text2, dp), solve(index1, index2-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {

        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        // return solve(text1.size()-1, text2.size()-1, text1, text2, dp);

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        // to accomodate the base cases, we do a shifting of indexes, since we cannot have index value as negative
        // for the dp array, in order to write tabulation
        //  perform a right shift of the indexes to achieve this

        for(int i=0;i<=text2.size();i++){
            dp[0][i] = 0;
        }

        for(int i=0;i<=text1.size();i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[text1.size()][text2.size()];



    }
};
// @lc code=end

