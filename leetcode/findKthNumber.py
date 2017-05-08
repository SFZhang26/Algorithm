# 440. K-th Smallest in Lexicographical Order

class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        cur=1
        k-=1
        while k>0:
            step=self.cal(n, cur, cur+1)
            if step<=k:
                cur+=1
                k-=step
            else:
                cur*=10
                k-=1
        return cur
    
    def cal(self, n, n1, n2):
        res = 0
        while n1<=n:
            res+=min(n+1,n2)-n1
            n1*=10
            n2*=10
        return res
