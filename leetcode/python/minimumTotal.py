# 120. Triangle

class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        dp=triangle[-1]
        for i in range(len(triangle)-1)[::-1]:
            for j in range(len(triangle[i])):
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j]
        return dp[0]
