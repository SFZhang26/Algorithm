# 650. 2 Keys Keyboard

class Solution:
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [n+1]*(n+1)
        dp[1] = 0
        for i in range(n+1):
            for k in range(1, int(math.sqrt(i))+1):
                if i%k ==0:
                    dp[i] = min(dp[i], dp[k] + int(i/k), dp[int(i/k)]+k)
        return dp[n]
