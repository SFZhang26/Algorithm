# 387. First Unique Character in a String

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        for i in range(len(s)):
            if s[i] not in s[0:i] and s[i] not in s[i+1:len(s)]:
                return i
        
        return -1
