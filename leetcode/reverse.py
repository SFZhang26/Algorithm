# 7. Reverse Integer

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        result=0
        n=abs(x)
        while n>0:
            result=result*10+n%10
            if result>2147483647:
                return 0
            n/=10
        
        if x<0:
            return -result
        else:
            return result