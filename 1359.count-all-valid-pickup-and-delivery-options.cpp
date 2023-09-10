#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        long slots = 2*n;

        long count = 1;

        while(slots>0){
            count = (slots*(slots-1)/2 * count)%mod;
            slots-=2;
        }

        return (int)count;
        
    }
};
// @lc code=end

