#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // using linked list cycle method
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow=0;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
// @lc code=end

