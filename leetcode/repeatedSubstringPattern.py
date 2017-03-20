# 459. Repeated Substring Pattern

class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for i in range(1,len(s)/2+1):
            if len(s)%i==0 and s==s[0:i]*(len(s)/i):
                return True
        return False
