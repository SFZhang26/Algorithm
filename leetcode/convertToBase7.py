# 504. Base 7

class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num==0:
            return "0"
        result=""
        sig="-" if num<0 else ""
        num=abs(num)
        while num>0:
            result=str(num%7)+result
            num/=7
        return sig+result
        
