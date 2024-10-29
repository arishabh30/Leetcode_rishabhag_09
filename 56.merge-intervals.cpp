#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= end){
                if(intervals[i][1] >= end){
                    end = intervals[i][1];
                }
                
            }
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
        
    }
};
// @lc code=end

