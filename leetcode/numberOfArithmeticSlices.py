# 413. Arithmetic Slices

class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if(len(A)<3):
            return 0
        dp=[0]*len(A)
        for i in range(2,len(A)):
            if(A[i]-A[i-1]==A[i-1]-A[i-2]):
                dp[i]=dp[i-1]+1
        
        return sum(dp)
