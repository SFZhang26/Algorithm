# 600. Non-negative Integers without Consecutive Ones

class Solution:
    def findIntegers(self, num):
        """
        :type num: int
        :rtype: int
        """
        dp=[0]*31
        dp[0], dp[1]= 1, 2
        for i in range(2,len(dp)):
            dp[i]=dp[i-2]+dp[i-1]
            
        s=bin(num)[2:]
        count=1
        res=dp[len(s)-1]+1
        for i in range(1,len(s)):
            if s[i]=='0':
                continue
            count+=1
            res+=dp[len(s)-1-i]
            if s[i-1]=='1':
                res-=1
                break
        return res
                        
            
