# 390. Elimination Game

class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.f(n)
    
    def f(self, n):
        if n==1:
            return 1
        if n==2:
            return 2
        return 2*self.g(n/2)
    
    def g(self, n):
        if n<=2:
            return 1
        if n&1:
            return 2*self.f(n/2)
        else:
            return 2*self.f(n/2)-1
        
