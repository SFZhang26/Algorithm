# 446. Arithmetic Slices II - Subsequence

class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        result=0
        if len(A)<3:
            return 0
        
        dp=[{} for i in A]
        
        for i in range(1,len(A)):
            for j in range(i):
                dif=A[i]-A[j]
                if dif in dp[i]:
                    dp[i][dif]+=1
                else:
                    dp[i][dif]=1
                if dif in dp[j]:
                    result+=dp[j][dif]
                    dp[i][dif]+=dp[j][dif]
                    
        return result
