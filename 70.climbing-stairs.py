#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        # dp = [-1]*(n+1)
        prev = 1
        curr = 1
        if(n<=1): 
            return 1

        for i in range(2, n+1):
            temp = prev + curr
            prev = curr
            curr = temp
        
        return curr
# @lc code=end

