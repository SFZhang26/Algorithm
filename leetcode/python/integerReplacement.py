# 397. Integer Replacement

class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n==1:
            return 0
        if n&1:
            return min(self.integerReplacement(n+1),self.integerReplacement(n-1))+1
        else:
            return self.integerReplacement(n/2)+1
