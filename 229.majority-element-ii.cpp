#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int count1 = 0, count2 = 0, element1, element2;

        for(int num : nums){
            if(count1==0 && num!=element2){
                count1 = 1;
                element1 = num;
            }
            else if(count2==0 && num!=element1){
                count2 = 1;
                element2 = num;
            }
            else if(num == element1){
                count1++;
            }
            else if(num == element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        int temp1 = 0, temp2 = 0;
        for(int num : nums){
            if(num == element1) temp1++;
            else if(num==element2) temp2++;
        }
        vector<int> ans;
        int n = nums.size();
        if(temp1>n/3){
            ans.push_back(element1);
        }
        if(temp2>n/3){
            ans.push_back(element2);
        }

        return ans;
        
    }
};
// @lc code=end

