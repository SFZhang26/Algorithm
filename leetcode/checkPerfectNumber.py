# 507. Perfect Number

import math

class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num<=5:
            return False
        result=0
        for i in range(2,int(math.sqrt(num))+1):
            if num%i==0:
                result+=(i+num/i)
        return num==(result+1)
