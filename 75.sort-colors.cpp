#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = 0;

        while(mid<=high){
            if(nums[mid] > 1){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid]<1){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else mid++;
        }

    }
};
// @lc code=end

