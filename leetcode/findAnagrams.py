# 438. Find All Anagrams in a String

class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        result=[]
        count=[0]*26
        if len(s)<len(p):
            return result
        for i in range(len(p)):
            count[ord(p[i])-ord('a')]+=1
            count[ord(s[i])-ord('a')]-=1
        if count==[0]*26:
            result.append(0)
        
        for i in range(len(p),len(s)):
            count[ord(s[i-len(p)])-ord('a')]+=1
            count[ord(s[i])-ord('a')]-=1
            if count==[0]*26:
                result.append(i-len(p)+1)
        
        return result
