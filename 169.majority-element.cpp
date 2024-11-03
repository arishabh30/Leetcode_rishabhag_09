#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        int count = 0;
        int element;
        for(int num : nums){
            if(count==0){
                element = num;
                count=1;
            }
            else if(element == num){
                count++;
            }
            else count--;
        }

        int temp = 0;
        for(int num : nums){
            if(num == element) temp++; 
        }
        if(temp > n/2) return element;
        return -1;


    }
};
// @lc code=end

