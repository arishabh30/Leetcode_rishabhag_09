#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1);
        }

        ans[0][0] = 1;
        for(int i=1;i<numRows; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }

        return ans;
    }
};
// @lc code=end

