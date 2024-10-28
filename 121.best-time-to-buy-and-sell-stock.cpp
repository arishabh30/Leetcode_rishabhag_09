#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int maxProfit = 0;
        int minVal = prices[0];

        for(int i=1;i<prices.size();i++){
            profit = prices[i] - minVal;
            maxProfit = max(profit, maxProfit);
            minVal = min(minVal, prices[i]);
        }     

        return profit;
    }
};
// @lc code=end

