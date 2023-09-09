/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int index, int target, vector<int>& nums){
        if(index==0){
            if(target==0 && nums[0]==0) return 2;
            if(abs(target) == nums[0]) return 1;
            else return 0;
        }

        // use -ve sign i.e., add to the target
        int add = solve(index-1, target + nums[index] , nums);
        int subtract = solve(index-1, target - nums[index], nums);

        return add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums.size()-1, target, nums);
        
    }
};
// @lc code=end

