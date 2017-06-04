# 552. Student Attendance Record II

class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD=1000000007
        a0=[0]*(n+1)
        a0[0]=1
        a0[1]=2
        a0l0=1
        a0l1=1
        a0l2=0
        for i in range(2,n+1):
            temp=a0l2
            a0l2=a0l1
            a0l1=a0l0
            a0l0=(a0l0+a0l2+temp)%MOD
            a0[i]=(a0l0+a0l1+a0l2)%MOD
        
        a1=0
        for k in range(n/2):
            a1=(a1+a0[k]*a0[n-1-k]*2)%MOD
        if n%2!=0:
            a1=(a1+a0[n/2]*a0[n/2])%MOD
        return (a0[n]+a1)%MOD
