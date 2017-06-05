# 576. Out of Boundary Paths

class Solution:
    def findPaths(self, m, n, N, i, j):
        """
        :type m: int
        :type n: int
        :type N: int
        :type i: int
        :type j: int
        :rtype: int
        """
        res=0
        MOD=1000000007
        dp_pre=[[0]*(n+2) for _ in range(m+2)]
        for a in range(m+2):
            dp_pre[a][0]=1
            dp_pre[a][n+1]=1
        for a in range(n+2):
            dp_pre[0][a]=1
            dp_pre[m+1][a]=1
        for k in range(N):
            dp_cur=[[0]*(n+2) for _ in range(m+2)]
            for a in range(1,m+1):
                for b in range(1,n+1):
                    dp_cur[a][b]=dp_pre[a-1][b]+dp_pre[a+1][b]+dp_pre[a][b-1]+dp_pre[a][b+1]
            dp_pre=dp_cur
            res=(res+dp_pre[i+1][j+1])%MOD   
        return res   
                
