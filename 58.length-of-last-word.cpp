#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> vec;

        int length = s.size();
        for(int i=0;i<length;i++){
            if(s[i] == ' ') continue;
            else{
                vec[i]+=s[i];
            };
        }

        string str = vec.back();

        return str.length();
    }
};
// @lc code=end

