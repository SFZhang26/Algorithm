# 13. Roman to Integer

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        dict={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        
        result=0
        for i in range(len(s)-1):
            if dict[s[i]]<dict[s[i+1]]:
                result-=dict[s[i]]
            else:
                result+=dict[s[i]]
        
        result+=dict[s[-1]]
        return result
