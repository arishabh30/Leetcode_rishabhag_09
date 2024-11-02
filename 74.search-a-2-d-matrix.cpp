#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();
        
        // for each value in the matrix, if the matrix is stretched into a 1d array
        // maintaining the sorted order that has been given its indices can be written as 
        // row = idx/n and col = idx%n
        // Taking this into account;

        int low = 0;
        int high = m*n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] < target){
                low = mid+1;
            }
            else if(matrix[row][col] > target){
                high = mid-1;
            }
            else{
                return true;
            }
        }

        return false;
        
    }
};
// @lc code=end

