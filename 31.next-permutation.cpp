#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int break_point;
        int n = nums.size();
        int flag = 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag = 1;
                break_point = i;
                break;
                // now swap the break_point element with the smallest element in the right subarray
            }
        }

        if(flag==0) return reverse(nums.begin(), nums.end());

        int minVal = INT_MAX;
        int minIdx = -1;
        for(int i=break_point+1; i<n;i++){
            if(nums[i] > nums[break_point]){
                minVal = min(minVal, nums[i]);
                if(minVal == nums[i]){
                    minIdx = i;
                }
            }
        }

        swap(nums[break_point], nums[minIdx]);

        // now reverse the right subarray;
        reverse(nums.begin()+break_point+1, nums.end());
    }
};
// @lc code=end

