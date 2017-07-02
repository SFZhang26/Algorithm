# 633. Sum of Square Numbers

class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        a,b=0, int(math.sqrt(c))+1
        while a<=b:
            res = a*a+b*b
            if res==c:
                return True
            elif res>c:
                b-=1
            else:
                a+=1
        return False
