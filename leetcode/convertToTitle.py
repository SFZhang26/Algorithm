# 168. Excel Sheet Column Title

class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        result=""
        while n>0:
            result=chr((n-1)%26 + 65)+result
            n=(n-1)/26;
        return result
