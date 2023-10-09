#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // implementing binary search 1
        vector<int> ans{-1,-1};
        int n = nums.size();

        // to find the first element, we will first find the element and then search the left subarray
        int l=0;
        int r = n-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target){
                ans[0] = mid;
                r = mid-1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
        }
        
        // to find the second element, we will again first find the element but this time will search in the right subarray
        l=0;
        r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                ans[1] = mid;
                l = mid+1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
        }
        
        return ans;


    }
};
// @lc code=end

