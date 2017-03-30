# 474. Ones and Zeroes

class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0]*(n+1) for i in range(m+1)]
        for s in strs:
            num_0=s.count('0')
            num_1=len(s)-num_0
            for i in range(num_0, m+1)[::-1]:
                for j in range(num_1, n+1)[::-1]:
                    dp[i][j]=max(dp[i][j], dp[i-num_0][j-num_1]+1)
        return dp[m][n]
        
